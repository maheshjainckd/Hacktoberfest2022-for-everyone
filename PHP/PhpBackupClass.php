<?php 
class PhpBackupClass{
    public $sourceFolder;
    public $destinationFolder;
    public $destinationBackUpFolderName;
    public $actionLog = [];
    
    public function __construct($source,$destination,$folderName='current'){
        $this->sourceFolder = $source;
        $this->destinationFolder = $destination;
        $this->destinationBackUpFolderName = $folderName;
    }

    public function getSourceFolder(){
        
        if(is_dir($this->sourceFolder)){
            $scanDirectory = $this->removeDotsFromDir($this->sourceFolder);
            return $scanDirectory;
        }

        return json_encode(['error'=>'No source folder found']);
    }

    public function getDestinationFolderWithFolderName(){
        return $this->destinationFolder."/".$this->destinationBackUpFolderName;
    }

    public function getDestinationFolder(){
        $destinationFolder = $this->getDestinationFolderWithFolderName();

        if(!is_dir($destinationFolder))
        {
            mkdir($destinationFolder,'0777',true);
            return $this->removeDotsFromDir($destinationFolder);
        }
        
        return $this->removeDotsFromDir($destinationFolder);
    }

    public function getFolderNameFromPath($path){
        $base = basename($path);
        return $base;
    }

    public function removeDotsFromDir($dir){
        return array_diff(scandir($dir),array('.','..'));
    }

    public function takeBackup(){
        
        $sourceFolderItems = $this->getSourceFolder();
        $destinationFolder = $this->getDestinationFolder();

        if(!empty($sourceFolderItems)){
            foreach($sourceFolderItems as $fileOrdir)
            {
                $copyFromPath = $this->sourceFolder.'/'.$fileOrdir;
                $copyToPath = $this->getDestinationFolderWithFolderName().'/'.$fileOrdir;

                if(is_dir($copyFromPath))
                {
                    $this->recursiveCopy($copyFromPath,$copyToPath);
                }
                else
                {
                    //if file exists in destination
                    if(file_exists($copyToPath))
                    {
                        $getSourceFileSize = filesize($copyFromPath);
                        $getDestinationFileSize = filesize($copyToPath);

                        //if file source file and destination file have different size
                        if($getSourceFileSize != $getDestinationFileSize)
                        {
                            $dateFolderPath = $this->destinationFolder.'/'.date('Ymd');
                            try{

                                if(!file_exists($dateFolderPath))
                                {
                                    mkdir($dateFolderPath,'0777',true);
                                    $this->actionLog['add'][] = 'Date Folder Created '.$dateFolderPath;
                                }

                                $copytoDateFolder = $dateFolderPath."/".$fileOrdir;
                                   
                                //first copy file to date folder
                                if(copy($copyFromPath,$copytoDateFolder))
                                {
                                    $this->actionLog['add'][] = 'File copied from '.$copyFromPath.' to '.$dateFolderPath;
                                    
                                    //once file copied to date folder 
                                    // now move original file to destination folder
                                    if(copy($copyFromPath,$copyToPath))
                                    {
                                        $this->actionLog['overwrite'][] = 'File overwrite from '.$copyFromPath.' to '.$copyToPath;
                                    }
                                }
                            }
                            catch(Exception $e)
                            {
                                echo 'Message: '.$e->getMessage();
                                exit();
                            }
                        }
                    }
                    else
                    {
                        if(copy($copyFromPath,$copyToPath))
                        {
                            $this->actionLog['add'][] = 'File copied from '.$copyFromPath.' to '.$copyToPath;
                        }
                    }
                }
            }
        }
        else{
            throw new Exception('Source Folder not found. Please check your Input');
        }

        if(count($destinationFolder) > 0)
        {
            foreach($destinationFolder as $fileOrDir)
            {
                $deleteFrom = $this->getDestinationFolderWithFolderName().'/'.$fileOrDir;
                $matchFrom = $this->sourceFolder.'/'.$fileOrDir;

            
                if(is_dir($deleteFrom))
                {
                    $this->recursiveDelete($deleteFrom,$matchFrom);

                }
                else
                {
                    if(!file_exists($matchFrom))
                    {
                        $createMovePath = $this->destinationFolder.'/'.date('Ymd').'/'.$fileOrDir;
                        
                        if(rename($deleteFrom,$createMovePath))
                        {
                            $this->actionLog['deleted'][] = 'File move and deleted from '.$deleteFrom.' to '.$createMovePath;
                        }
                    }
                }
                
            }
        }

        return (count($this->actionLog) > 0)?$this->actionLog:' All files and folder already updated';
       
    }

    private function recursiveCopy($source,$destination)
    {
        
        $sourceFolder = $this->removeDotsFromDir($source);

        //first check destination folder exist or not
        if(!file_exists($destination))
        {
            mkdir($destination);
            $this->actionLog['add'][] = 'Folder Created '.$destination;
        }
        
        foreach($sourceFolder as $fileOrdir)
        {
            $copyFromPath = $source.'/'.$fileOrdir;
            $copyToPath = $destination.'/'.$fileOrdir;

            if(is_dir($source.'/'.$fileOrdir))
            {
                $this->recursiveCopy($copyFromPath,$copyToPath);
            }
            else
            {
                if(file_exists($copyToPath))
	            {
                    $getSourceFileSize = filesize($copyFromPath);
		            $getDestinationFileSize = filesize($copyToPath);

                    $getBackupPath = str_replace($this->getDestinationFolderWithFolderName(),'',$copyToPath);
                    $splitBackUpPath = pathinfo($getBackupPath);
                    $trimBackUpPath = trim($splitBackUpPath['dirname'],'/');

                    if($getSourceFileSize!=$getDestinationFileSize)
                    {
                        $dateFolderPath =$this->destinationFolder.'/'.date('Ymd').'/'.$trimBackUpPath;

                        $dateFilePath = $dateFolderPath.'/'.$fileOrdir;

                        if(!file_exists($dateFolderPath))
                        {
                            mkdir($dateFolderPath,'0777',true);
                             $this->actionLog['add'][] = 'Date Folder Created '.$dateFolderPath;
                        }
                        
                        //copy destination file to date folder
                        if(copy($copyToPath,$dateFilePath))
                        {
                            $this->actionLog['add'][] = 'File copied from '.$copyToPath.' to '.$dateFilePath;

                            //once file copied to date folder 
                            // now move original file to destination folder
                            if(copy($copyFromPath,$copyToPath))
                            {
                                $this->actionLog['overwrite'][] = 'File overwrite from '.$copyFromPath.' to '.$copyToPath;
                            }
                        }
                        
                    }
                }
                else
                {
                    if(copy($copyFromPath,$copyToPath))
                    {
                         $this->actionLog['add'][] = 'File copied from '.$copyFromPath.' to '.$copyToPath;
                    }
                }        
            }
        }
    }

    private function recursiveDelete($deleteFrom,$matchFrom)
    {
        if(is_dir($matchFrom))
        {
            $deleteFromDir = $this->removeDotsFromDir($deleteFrom);
            $matchFromDir = $this->removeDotsFromDir($matchFrom);
            $folderDiff = array_diff($deleteFromDir,$matchFromDir);

            foreach($deleteFromDir as $tobeDeletedFileOrDir)
            {
                $deleteFilePath = $deleteFrom."/".$tobeDeletedFileOrDir;
                $matchFilePath = $matchFrom."/".$tobeDeletedFileOrDir;
                    
                if(in_array($tobeDeletedFileOrDir,$matchFromDir))
                {
                    if(is_dir($deleteFilePath))
                    {
                        $this->recursiveDelete($deleteFilePath,$matchFilePath);
                    }

                }
                else
                {
                    if(is_dir($deleteFilePath))
                    {
                        $this->recursiveDelete($deleteFilePath,$matchFilePath);
                    }
                    else
                    {
                        //remove destination folder name from folder to copy in date folder
                        $trimDesitnationFolder = trim(str_replace($this->getDestinationFolderWithFolderName(),'',$deleteFrom),'/');
                        
                        $createMovePath = $this->destinationFolder.'/'.date('Ymd').'/'.$trimDesitnationFolder.'/'.$tobeDeletedFileOrDir;

                        if(rename($deleteFilePath,$createMovePath))
                        {
                            $this->actionLog['deleted'][] = 'File move and deleted from '.$deleteFrom.' to '.$createMovePath;
                        }
                    }
                }
            }
        }
        else
        {
            $deleteFromDir = $this->removeDotsFromDir($deleteFrom);
            if(count($deleteFromDir) > 0)
            {
                foreach($deleteFromDir as $dfileOrDir)
                {
                    $deleteFilePath = $deleteFrom.'/'.$dfileOrDir;
                    $matchFilePath = $matchFrom.'/'.$dfileOrDir;
                    if(is_dir($deleteFilePath))
                    {
                        $this->recursiveDelete($deleteFilePath,$matchFilePath);
                    }
                    else
                    {
                        $trimDesitnationFolder = trim(str_replace($this->getDestinationFolderWithFolderName(),'',$deleteFrom),'/');
                        
                        $createMovePath = $this->destinationFolder.'/'.date('Ymd').'/'.$trimDesitnationFolder.'/'.$dfileOrDir;

                        if(rename($deleteFilePath,$createMovePath))
                        {
                             $this->actionLog['deleted'][] = 'File move and deleted from '.$deleteFilePath.' to '.$createMovePath;
                        }
                    }
                }
            }
            else
            {
                if(rmdir($deleteFrom))
                {
                    $this->actionLog['deleted'][] = 'Removed Empty Folder '.$deleteFrom;
                }
            }
        }
    }

    public function backupReport($startDate,$endDate)
    {
        
        $fromDate = new DateTime($startDate);
        $toDate = new DateTime($endDate);
        $dateDiff = $toDate->diff($fromDate);

        $dateArray = [];
        for($fromDate;$fromDate<=$toDate;$fromDate->add(new DateInterval('P1D')))
        {
            $folderName = $fromDate->format('Ymd');
            $folderPath = $this->destinationFolder.'/'.$folderName;

            if(is_dir($folderPath))
            {
                $folderFileAndDirArray = $this->removeDotsFromDir($folderPath);
                
                if(!empty($folderFileAndDirArray))
                {
                    $newArray = [];
                    foreach($folderFileAndDirArray as $fileOrDir)
                    {
                        $innerFolderPath = $folderPath."/".$fileOrDir;
                        
                        if(is_dir($innerFolderPath))
                        {
                            $dateArray[$fromDate->format('Y-m-d')][] = $this->reportFolderRecursive($innerFolderPath);
                        }
                        else
                        {
                            $dateArray[$fromDate->format('Y-m-d')][] =$innerFolderPath;
                        }
                    }
                    
                }
            }
        }

        $flattenArray = [];
        foreach($dateArray as $date => $valueOrArray)
        {
            $flattenArray[$date] = $this->arrayFlatten($valueOrArray);
        }

        $output='<table border="1" style="border-collapse: collapse;width:100%;">';
        $output.='<tr>';
        $output.='<th>Date</th>';
        $output.='<th>Status</th>';
        $output.='</tr>';
        foreach($flattenArray as $date => $array)
        {
            $countItems = count($array)+1;
            $output.='<tr>';
                $output.='<td rowspan="'.$countItems.'">'.$date.'</td>';
            $output.='</tr>';

            foreach($array as $value)
            {
                $output.='<tr>';
                $output.='<td>'.$value.'</td>';
                $output.='</tr>';
            }
           
        }
        
        $output.='<table>';

       return $output;
    }

    public function arrayFlatten($array,$return=[]) { 
        
        for($x = 0; $x <= count($array); $x++) {
            if(isset($array[$x]) && is_array($array[$x])) {
                $return = $this->arrayFlatten($array[$x], $return);
            }
            else {
                if(isset($array[$x])) {
                    $return[] = $array[$x];
                }
            }
	    }

	    return $return;
    } 

    private function reportFolderRecursive($folderPath)
    {

        if(is_dir($folderPath))
        {
            $folderFileAndDirArray = $this->removeDotsFromDir($folderPath);
            if(!empty($folderFileAndDirArray))
            {
                $array = [];
                foreach($folderFileAndDirArray as $fileOrDir)
                {
                    $path = $folderPath."/".$fileOrDir;
                    if(is_dir($path))
                    {
                        $innerFolderPath = $folderPath."/".$fileOrDir;
                        $array[] = $this->reportFolderRecursive($innerFolderPath);
                    }
                    else
                    {
                        $array[] =$folderPath.'/'.$fileOrDir;
                    }
                }

                return $array;
            }
        }
    }

    public function exportDateFolder($date,$path)
    {
        $newDate = date('Ymd',strtotime($date));

        $createDestinationPath = $this->destinationFolder.'/'.$newDate;
        if(is_dir($createDestinationPath))
        {
            if(is_dir($path))
            {
                if(!is_dir($path.'/'.$newDate))
                {
                    mkdir($path.'/'.$newDate);
                }

                $dateFolderArray = $this->removeDotsFromDir($createDestinationPath);

                if(!empty($dateFolderArray))
                {
                    foreach($dateFolderArray as $fileOrDir)
                    {
                        $copyFromPath = $createDestinationPath.'/'.$fileOrDir;
                        $copyToPath = $path.'/'.$newDate.'/'.$fileOrDir;

                        if(is_dir($copyFromPath))
                        {
                            $this->recursiveExport($copyFromPath,$copyToPath);
                        }
                        else
                        {
                              copy($copyFromPath,$copyToPath);
                        }
                    }
                }

                return 'Done';
            }

            return 'Path not found';
        }
        
        return [];
    }

    private function recursiveExport($source,$destination){
         $sourceFolder = $this->removeDotsFromDir($source);
         
        if(!file_exists($destination))
        {
            mkdir($destination);
            $this->actionLog['add'][] = 'Folder Created '.$destination;
        }

        foreach($sourceFolder as $fileOrdir)
        {
            $copyFromPath = $source.'/'.$fileOrdir;
            $copyToPath = $destination.'/'.$fileOrdir;
            
            if(is_dir($source.'/'.$fileOrdir))
            {
                $this->recursiveExport($copyFromPath,$copyToPath);
            }
            else
            {
                copy($copyFromPath,$copyToPath);
            }
        }
    }

    public function singleDayReport($date){
        $date = new DateTime($date);
        $folderPath = $this->destinationFolder.'/'.$date->format('Ymd');
        
        if(is_dir($folderPath))
        {
            $folderFileAndDirArray = $this->removeDotsFromDir($folderPath);
            if(!empty($folderFileAndDirArray))
            {
                foreach($folderFileAndDirArray as $fileOrDir)
                {
                    $innerFolderPath = $folderPath."/".$fileOrDir;
                    if(is_dir($innerFolderPath))
                    {
                        $dateArray[$date->format('Y-m-d')][] = $this->reportFolderRecursive($innerFolderPath);
                    }
                    else
                    {
                        $dateArray[$date->format('Y-m-d')][] =$innerFolderPath;
                    }
                }

                 $flattenArray = [];
                    foreach($dateArray as $date => $valueOrArray)
                    {
                        $flattenArray[$date] = $this->arrayFlatten($valueOrArray);
                    }

                    $output='<table border="1" style="border-collapse: collapse;width:100%;">';
                    $output.='<tr>';
                    $output.='<th>Date</th>';
                    $output.='<th>Status</th>';
                    $output.='</tr>';
                    foreach($flattenArray as $date => $array)
                    {
                        $countItems = count($array)+1;
                        $output.='<tr>';
                            $output.='<td rowspan="'.$countItems.'">'.$date.'</td>';
                        $output.='</tr>';

                        foreach($array as $value)
                        {
                            $output.='<tr>';
                            $output.='<td>'.$value.'</td>';
                            $output.='</tr>';
                        }
                    
                    }
                    
                    $output.='<table>';

                return $output;
            }
        }

        return 'Folder not found';
    }
}


$source = 'source';
$desination = 'destination';
$backup = new PhpBackupClass($source,$desination);

if(is_array($backup->takeBackup()) && !empty($backup->takeBackup()))
{
    
    $ul = '<ul>';
    foreach($backup->takeBackup() as $key => $value)
    {
        $ul .='<li>'.$key;
        if(is_array($value))
        {
            $ul .= '<ul>';
            foreach($value as $message)
            {
                $ul .='<li>'.$message.'</li>';
            }
            $ul .= '</ul>';
        }
        $ul .= '</li>';
    }
    $ul .= '</ul>';

    echo $ul;
}
else
{
    //echo $backup->takeBackup();
}


//$from = '2021-03-03';
//$to = '2021-03-03';
//$report = $backup->backupReport($from,$to);
//echo $report;

$date = '2021-03-03';
$singleDayReport = $backup->singleDayReport($date);
echo $singleDayReport;

//$date = '2021-03-03';
//$path = '../ahsan/';
//$exportFolder = $backup->exportDateFolder($date,$path);

//echo "<br>";
//echo $exportFolder;

