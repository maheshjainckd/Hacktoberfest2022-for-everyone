#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h>
#define MAXCHAR 1000
int main()
{
	int num;
	char name[30];
	int array[10];
    int x, p;
    int score=0;
    int count;
    int i=0;
    char str[MAXCHAR];
     FILE *hs;
    menu:
printf("\n\t   +-------+                          _______        _______           _______          _______        _________                         _________     ");
printf("\n\t   |       |      |         |            |                 /                 /             |          |                |                |              ");
printf("\n\t   |       |      |         |            |                /                 /              |          |                |                |              ");
printf("\n\t   |       |      |         |            |               /                 /               |          |                |                |_________     ");
printf("\n\t   |    // |      |         |            |              /                 /                |          |                |                |              ");
printf("\n\t   |   //  |      |         |            |             /                 /                 |          |                |                |              ");
printf("\n\t   +--//---+      |_________|         ___|___         /_______          /_______        ___|____      |_________       |_________       |_________     \n\n\n");
printf("Press Enter to Start the Game\n");     
     getch();
     system("cls");

	printf("\n\n\n\n\n\n\n\n                        Register Your Name:");
	gets(name);

	system("cls");
    home:
	printf("                       Welcome %s to the Quizzicle                        \n",name);
	printf("                          By Siddharth and Dev                            \n");
	printf("\n\n\n\n\n\n");

	printf("                      Press S to Start the Game.\n");
	
    printf("                      Press H to view Highscores.\n");
    
    printf("                      Press I to view Instructions.\n");
	
	
	if (toupper(getch()) == 'H')
    {
		system("cls");
            hs = fopen("highscore.txt", "r");
            while (fgets(str, MAXCHAR, hs) != NULL)
        printf("%s", str);
    fclose(hs);
    getch();
    system("cls");
    goto home;

    }
    
if (toupper(getch()) == 'I')
	{
		system("cls");

		printf("\n >> There are 5 categpries in this Quiz Game --> Logical Reasoning,History,Books and Author,\n");
		printf("    Sports,General Science");
		printf("\n >> In each categories you will be asked a total of 10 questions.");
		printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
		printf("\n    right option.");
		printf("\n >> No negative marking for wrong answers!");
		printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
	   getch();
       system("cls");
       goto home;
    
    
    }
	//Start the Game
	if (toupper(getch()) == 'S')
		system("cls");
	{

		printf("Choose Your Category:\n");

		printf("1-Logical Reasoning\n");
		printf("2-History\n");
		printf("3-Books and Author\n");
        printf("4-Sports\n");
		printf("5-General Science\n");
		scanf("%d", &num);
	    system("cls");
	
	}

	switch (num)
	{

	 case 1:
	
 
    srand(time(NULL));

    for(count=0;count<10;count++){
        array[count]=rand()%40+0;
    }

    while(i<10){
        int r=rand()%40+1;

        for (x = 0; x < i; x++)
        {
            if(array[x]==r){
                break;
            }
        }
        if(x==i){
            array[i++]=r;
        }
    }
    for(p=0;p<10;p++)
	{
        int r=array[p];

		
    if(r==1)
		{printf("Question-%d:RQP, ONM, _, IHG, FED, find the missing letters.\nA)CDE\nB)LKI\nC)LKJ\nD)BAC",p+1);
        if(toupper(getch()) == 'C')
        {score++;
		system("cls");
        }
        else{
        system("cls");
        continue;}}

	if(r==2)
		{printf("Question-%d:PETAL: FLOWER\nA)PEN:PAPER\nB)ENGINE:CAR\nC)CAT:DOG\nD)BALL:GAME",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
		
	if(r==3)
		{printf("Question-%d:Which word does not belong to others?\nA)Inch\nB)Kilogram\nC)Centimeter\nD)Yard",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==4)
		{printf("Question-%d:Pointing to a photograph, a man said,'I have no brother,and that man's father is my father's son.'Whose photograph was it?\n",p+1);
		printf("A)His Son\nB)His Own\nC)His Father\nD)His Nephew");
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==5)
		{printf("Question-%d:Peter is in the East of Tom and Tom is in the North of John. Mike is in the South of John then in which direction of Peter is Mike?\n",p+1);
		printf("A)South-East\nB)South-West\nC)South\nD)North East");
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==6)
		{printf("Question-%d:An animal always has\nA)Skin\nB)Heart\nC)Lungs\nD)Life",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==7)
		{printf("Question-%d:If in a certain language, NOIDA is coded as OPJEB, how is DELHI coded in that language?\nA)CDKGH\nB)EFMIJ\nC)FGNJK\nD)IHLED",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==8)
		{printf("Question-%d:Look at this series: 7, 10, 8, 11, 9, 12, ... What number should come next?\nA)7\nB)10\nC)12\nD)13",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==9)
		{printf("Question-%d:Look at this series: 36, 34, 30, 28, 24, ... What number should come next?\nA)20\nB)22\nC)23\nD)26",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==10)
		{printf("Question-%d:Look at this series: 22, 21, 23, 22, 24, 23, ... What number should come next?\nA)22\nB)24\nC)25\nD)26",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==11)
		{printf("Question-%d:Which word does NOT belong with the others?\nA)Parsley\nB)Basil\nC)Dill\nD)MAyonnaise",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==12)
		{printf("Question-%d:Which word does NOT belong with the others?\nA)Tyre\nB)Steering Wheel\nC)Engine\nD)Car",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==13)
		{printf("Question-%d:Which word does NOT belong with the others?\nA)Core\nB)Seeds\nC)Pulp\nD)Slice",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==14)
		{printf("Question-%d:Odometer is to mileage as compass is to\nA)Speed\nB)Hiking\nC)Needle\nD)Direction",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==15)
		{printf("Question-%d:Cup is to coffee as bowl is to\nA)Dish\nB)Soup\nC)Spoon\nD)Food",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==16)
		{printf("Question-%d:BINDING : BOOK\nA)CRIMINAL:GANG\nB)DISPLAY:MUSEUM\nC)ARTIST:CARPENTER\nD)FRAME:PICTURE",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==17)
		{printf("Question-%d:EXPLORE : DISCOVER\nA)READ:SKIM\nB)RESEARCH:LEARN\nC)WRITE:PRINT\nD)SLEEP:WAKE",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    
	if(r==18)
		{printf("Question-%d:SLAPSTICK:LAUGHTER\nA)FALLACY:DISMAY\nB)GENRE:MYSTERY\nC)SATIRE:ANGER\nD)HORROR:FEAR",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	

	if(r==19)
		{printf("Question-%d:SCD, TEF, UGH, ____, WKL\nA)CMN\nB)UJI\nC)VIJ\nD)IJT",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
   
    if(r==20)
		{printf("Question-%d:FAG, GAF, HAI, IAH, ____\nA)JAK\nB)HAL\nC)HAK\nD)JAI",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==21)
		{printf("Question-%d:CMM, EOO, GQQ, _____, KUU\nA)GRR\nB)GSS\nC)ISS\nD)ITT",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==22)
		{printf("Question-%d:ELFA, GLHA, ILJA, _____, MLNA\nA)OLPA\nB)KLMA\nC)LLMA\nD)KLLA",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==23)
		{printf("Question-%d:Which word does NOT belong with the others?\nA)Fair\nB)Just\nC)Equitable\nD)Favorable",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==24)
		{printf("Question-%d:Tanya is older than Eric.\nCliff is older than Tanya.\nEric is older than Cliff.\n",p+1);
		printf("If the first two statements are true, the third statement is\nA)True\nB)False\nC)Uncertain");
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
    
	if(r==25)
		{printf("Question-%d:Blueberries cost more than strawberries.\nBlueberries cost less than raspberries.\n",p+1);
		printf("Raspberries cost more than strawberries and blueberries.\nIf the first two statements are true, the third statement is\nA)True\nB)False\nC)Uncertain");
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==26)
	    {printf("Question-%d:All the trees in the park are flowering trees.\nSome of the trees in the park are dogwoods.\nAll dogwoods in the park are flowering trees.\n",p+1);
        printf("If the first two statements are true, the third statement is\nIf the first two statements are true, the third statement is\nA)True\nB)False\nC)Uncertain");
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==26)
		{printf("Question-%d:Mara runs faster than Gail.\nLily runs faster than Mara.\nGail runs faster than Lily.\n",p+1);
        printf("If the first two statements are true, the third statement is\nA)True\nB)False\nC)Uncertain");
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==27)
		{printf("Question-%d:Apartments in the Riverdale Manor cost less than apartments in The Gaslight Commons.\n",p+1);
		printf("Apartments in the Livingston Gate cost more than apartments in the The Gaslight Commons.\n");
        printf("Of the three apartment buildings, the Livingston Gate costs the most.\n");
        printf("If the first two statements are true, the third statement is\nA)True\nB)False\nC)Uncertain");
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==28)
		{printf("Question-%d:Which word does NOT belong with the others?\nA)Aorta\nB)Heart\nC)Liver\nD)Stomach",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==29)
		{printf("Question-%d:Which word does NOT belong with the others?\nA)Mayor\nB)Lawyer\nC)Governer\nD)Senator",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==30)
		{printf("Question-%d:Which word does NOT belong with the others?\nA)Seat\nB)Rung\nCushion\nD)Leg",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==31)
		{printf("Question-%d:Look at this series: V, VIII, XI, XIV, __, XX, ... What number should fill the blank?\nA)IX\nB)XXIII\nC)XV\nD)XVII",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==32)
		{printf("Question-%d:Look at this series: F2, __, D8, C16, B32, ... What number should fill the blank?\nA)A16\nB)G4\nC)E4\nD)E3",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==33)
		{printf("Question-%d:6 10 14 18 22 26 30\nA)36 40\nB)33 37\nC)38 42\nD)34 38",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==34)
		{printf("Question-%d:36 31 29 24 22 17 15\nA)13 11\nB)10 5\nC)12 7\nD)10 8",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==35)
		{printf("Question-%d:3 5 35 10 12 35 17\nA)22 35\nB)35 19\nC)19 35\nD)19 24",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==36)
		{printf("Question-%d:Class A has a higher enrollment than Class B.\n",p+1);
        printf("Class C has a lower enrollment than Class B.\n");
        printf("Class A has a lower enrollment than Class C.\n");
        printf("If the first two statements are true, the third statement is\nA)True\nB)False\nC)Uncertain");
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==37)
		{printf("Question-%d:Four people witnessed a mugging. Each gave a different description of the mugger. Which description is probably right?\n",p+1);
		printf("A)He was average height, thin, and middle-aged.\nB)He was tall, thin, and middle-aged.");
		printf("\nC)He was tall, thin, and young.\nD)He was tall, of average weight, and middle-aged.");
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==38)
		{printf("Question-%d:Ms. Forest likes to let her students choose who their partners will be; however, no pair of students may work together more than seven class periods",p+1);
		printf("in a row. Adam and Baxter have studied together seven class periods in a row. Carter and Dennis have worked together three class periods in a row.");
		printf("Carter does not want to work with Adam. Who should be assigned to work with Baxter?\n");
		printf("A)Carter\nB)Adam\nC)Dennis\nD)Forest");
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==39)
		{printf("Question-%d:In a four-day period Monday through Thursday each of the following temporary office workers worked only one day, each a different day.",p+1);
		printf("Ms.Johnson was scheduled to work on Monday,");
		printf("but she traded with Mr. Carter, who was originally scheduled to work on Wednesday. Ms. Falk traded with Mr. Kirk, who was originally scheduled to work on Thursday.");
		printf("After all the switching was done, who worked on Tuesday?\n");
		printf("A)Mr. Carter\nB)Mr. Falk\nC)Mr. Johnson\nD)Mr. Kirk");
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==40)
		{printf("Question-%d:Four defensive football players are chasing the opposing wide receiver, who has the ball. Calvin is directly behind the ball carrier.",p+1);
		printf("Jenkins and Burton are side by side behind Calvin. Zeller is behind Jenkins and Burton.");
		printf("Calvin tries for the tackle but misses and falls. Burton trips. Which defensive player tackles the receiver?\n");
		printf("A)Burton\nB)Zeller\nC)Jenkins\nD)Calvin");
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	}

    printf("You scored %d marks out of 10",score);
     hs=fopen("highscore.txt","ab");
    
     fprintf(hs,"\n%s --> %d",name,score);
     fclose(hs);
    printf("\nPress Enter to return Main Menu");
     getch();
     system("cls");
     goto menu;
	 break;
	
	
case 2:
		
    srand(time(NULL));

    for(count=0;count<10;count++){
        array[count]=rand()%40+0;
    }

    while(i<10){
        int r=rand()%40+1;

        for (x = 0; x < i; x++)
        {
            if(array[x]==r){
                break;
            }
        }
        if(x==i){
            array[i++]=r;
        }
    }
    for(p=0;p<10;p++)
	{
        int r=array[p];
       
	    if(r==1)
		{printf("Question-%d:What was Napoleon's last name?\nA)Bonaparte\nB)Levant\nC)La Croix\nD)de Leon",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

       if(r==2)
		{printf("Question-%d:Which country is famous for the Inquisition?\nA)Spain\nB)America\nC)Brazil\nD)India",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
 
      if(r==3)
		{printf("Question-%d:What event prompted the US to enter World War II?\nA)The Holocaust\nB)Japan bombing Pearl Harbor\nC)a treaty with the UK\nD)The US never entered WWII.",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
 
     if(r==4)
		{printf("Question-%d:When was the Victorian era?\nA)1815-1875\nB)1837-1901\nC)1600-1954\nD)1911-1931",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
 
     if(r==5)
		{printf("Question-%d:What language did Ancient Romans speak?\nA)Latin\nB)Gaelic\nC)Chinese\nD)Arabic",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
 
     if(r==6)
		{printf("Question-%d:____________ fell in 1991.\nA)The Ottoman Empire\nB)The Roman Empire\nC)The USSR\nD)Norway",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

      if(r==7)
		{printf("Question-%d:Who was the first president of the United States?\nA)Thomas Jefferson\nB)Paul Revere\nC)Ronald Reagan\nD)George Washington",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

     if(r==8)
		{printf("Question-%d:Where was gunpowder invented?\nA)America\nB)Germany\nC)The Ottoman Empire\nD)China",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

     if(r==9)
		{printf("Question-%d:How many U.S. presidents have been assassinated?\nA)0\nB)1\nC)4\nD)9",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

     if(r==10)
		{printf("Question-%d:In Western Europe, the time between the fall of Rome and the Renaissance is called the ___________.\nA)Centurion Era\nB)Metazoic period\nC)Middle Ages\nD)Gothic Era",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

     if(r==11)
		{printf("Question-%d:Which of The Seven Wonders of the Ancient World can still be seen today?\nA)The Great Pyramid of Giza\nB)The Lighthouse of Alexandria\nC)The Statue of Zeus\nD)The Hanging Gardens of Babylon",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==12)
		{printf("Question-%d:Who was the last ruler of Egypt?\nA)Moses\nB)Cleopatra\nC)Tutankhamen\nD)Khufu",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==13)
		{printf("Question-%d:Did anyone named in the Bible actually exist?\nA)Yes\nB)No",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==14)
		{printf("Question-%d:Did anyone named in the Bible actually exist?\nA)Yes\nB)No",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==15)
		{printf("Question-%d:Why was Stonehenge built?\nA)No One Knows\nB)Religious Ceremonies\nC)to keep track of time\nD)It's a royal tomb.",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==16)
		{printf("Question-%d:The sun never sets on the _________ Empire.\nA)British\nB)Canadian\nC)Ghanian\nD)Egyptian",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==17)
		{printf("Question-%d:A portion of the world's population is thought to be descended from which global conqueror?\nA)Alexander the Great\nB)Genghis Khan\nC)Darius the Great\nD)Napoleon Bonaparte",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==18)
		{printf("Question-%d:Where do the first historical accounts of coffee come from?\nA)The Middle East\nB)India\nC)Europe\nD)Australia",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==19)
		{printf("Question-%d:Were the Hanging Gardens of Babylon real?\nA)Yes\nB)No\nC)No One is Sure\nD)They can still be seen today",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==20)
		{printf("Question-%d:What did Columbus hope to find on his expeditions?\nA)Gold\nB)Slaves\nC)a route to Asia\nD)the end of the world",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	
	if(r==21)
		{printf("Question-%d:What kind of warfare is the Cold War known for?\nA)Blitzkrieg\nB)Trench Warfare\nC)Proxy Wars\nD)Guerilla Warfare",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==22)
		{printf("Question-%d:Why did the Roman Empire split in half?\nA)They lost half of their land in war\nB)It was too large to govern\nC)It was collapsing\nD)Vikings split it up",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==23)
		{printf("Question-%d:Which country had colonies in the Americas?\nA)France\nB)Spain\nC)Great Britain\nD)All of the Above",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==24)
		{printf("Question-%d:Who was the leader and face of the Nazi party?\nA)Adolf Hitler\nB)Sargon of Akkad\nC)Richard Nixon\nD)Napoleon Bonaparte",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==25)
		{printf("Question-%d:Who is credited with inventing the telephone?\nA)Thomas Edison\nB)Chandragupta\nC)Alexander Graham Bell\nD)Benjamin Franklin",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==26)
		{printf("Question-%d:During which war did the British burn down Washington, D.C.?\nA)The Civil War\nB)The Cold War\nC)The Korean War\nD)The War of 1812",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==27)
		{printf("Question-%d:While Western Europe languished during the Middle Ages, which civilization was thriving culturally?\nA)Islamic\nB)Russian\nC)Cherokee\nD)Mongol",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==28)
		{printf("Question-%d:The Crusades were fought by Christians and ________.\nA)Muslims\nB)Catholics\nC)Jews\nD)Hindus",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==29)
		{printf("Question-%d:Who was the last czar of Russia?\nA)Nicholas II\nB)Peter the Great\nC)Charlemagne\nD)Adolf Hitler",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==30)
		{printf("Question-%d:The Great Pyramid at Giza was built under which Pharaoh?\nA)Cleopatra\nB)Ramses\nC)Khufu\nD)Tutankhamen",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==31)
		{printf("Question-%d:Where is the area which is described as 'the cradle of civilization' or 'the fertile crescent'?\nA)The Middle East and Africa\nB)Europe and Asia\nC)North America\nD)Australia",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==32)
		{printf("Question-%d:Which places did Alexander the Great's empire stretch into?\nA)Jerusalem\nB)India\nC)Babylon\nD)All of the Above",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==33)
		{printf("Question-%d:Which of these countries had colonies in Africa?\nA)France\nB)Great Britain\nC)Portugal\nD)All of the Above",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==34)
		{printf("Question-%d:Which of these languages, which is still spoken today, has been in use for over 2,000 years?\nA)French\nB)English\nC)Tamil\nD)Russian",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==35)
		{printf("Question-%d:The oldest existing proof of written law is known as the Code of ________.\nA)Sargon\nB)Tutankhamen\nC)Napoleon\nD)Hammurabi",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==36)
		{printf("Question-%d:Which of these Asian countries avoided colonial rule?\nA)India\nB)The Philippines\nC)Vietnam\nD)Thailand",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==37)
		{printf("Question-%d:Hathigumpha inscription gives account of which of the following rulers?\nA)Asoka\nB)Chandragupta Maurya\nC)Kharvela\nD)Samudragupya",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==38)
		{printf("Question-%d:Who was the author of Aihole Inscription ?\nA)Ravikirti\nB)Hiuen Tsang\nC)Bharavi\nD)Dandin",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==39)
		{printf("Question-%d:The Ashoka’s Bairut inscription was brought to Allahabad by__?\nA)Cunningham\nB)James Princep\nC)Feroj Shah Tughlaq\nD)Jahangir",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	if(r==40)
		{printf("Question-%d:Who among the following Pallava ruler built Vaikuntaperumal temple at Kanchi ?\nA)Nandivarman II\nB)Aparajita\nC)Mahendrvarman I\nD)Vikramaditta II",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
	
	
	}
	

	printf("Your score is %d out of 10.",score);
    
	 hs=fopen("highscore.txt","ab");
    
     fprintf(hs,"\n%s --> %d",name,score);
     fclose(hs);
	
    printf("\nPress Enter to return Main Menu");
     getch();
     system("cls");
     goto menu;
    
    break;
	case 3:
		
    	
    srand(time(NULL));

    for(count=0;count<10;count++){
        array[count]=rand()%40+0;
    }

    while(i<10){
        int r=rand()%40+1;

        for (x = 0; x < i; x++)
        {
            if(array[x]==r){
                break;
            }
        }
        if(x==i){
            array[i++]=r;
        }
    }
    for(p=0;p<10;p++)
	{
        int r=array[p];
    
	if(r==1)
		{printf("Question-%d:Who wrote the famous book -'We the people'?\nA)T.N.Kaul\nB)J.R.D. Tata\nC)Khushwant Singh\nD)Nani Palkhivala",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==2)
		{printf("Question-%d:Which of the following is NOT written by Munshi Premchand?\nA)Gaban\nB)Godan\nC)Guide\nD)Manasorovar",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==3)
		{printf("Question-%d:Who is the author of the book 'Nineteen Eighty Four'?\nA)Thomas Hardy\nB)Emile Zola\nC)George Orwell\nD)Walter Scott",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==4)
		{printf("Question-%d:Author of Around the World in Eighty Days is\nA)William Shakespeare\nB)Richard\nC)U.S.Naipaul\nD)Jules Verne",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

     if(r==5)
		{printf("Question-%d:Who wrote the Book “Gandhi and Stalin”\nA)Raj Narayan\nB)Louis Fisher\nC)Anita Desai\nD)V.S.Naipaul",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==6)
		{printf("Question-%d:Who is the author of ‘Death in The Castle’?\nA)Thomas Mann\nB)H.P Nanda\nC)Pearl S. Buck\nD)John Gunther",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==7)
		{printf("Question-%d:Who is the author of “Divine Comedy”?\nA)Goethe\nB)Milton\nC)Dante\nD)Shakespeare",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

     if(r==8)
		{printf("Question-%d:Which among the following is not a work of Rabindranath Tagore?\nA)Chitra\nB)Kapala Kundala\nC)The Court Dancer\nD)Chithrangada",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==9)
		{printf("Question-%d:Author of The Diary of a young girl is\nA)Rachel Carson\nB)Roland Barthes\nC)Anne Frank\nD)Ibn battuta",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==10)
		{printf("Question-%d:A Gift of Monotheists\nA)Ram Mohan Roy\nB)Ashapurna Devi\nC)Boris Pasternak\nD)David Foster Wallace",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==11)
		{printf("Question-%d:'Glimpses of World history' Written by ?\nA)Rabindranath tagore\nB)H G Wells\nC)Mark twain\nD)Jawaharlal Nehru",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}
 
    if(r==12)
		{printf("Question-%d: The famous book “The General Theory of Employment, Interest and Money” is written by\nA)J.B.Say\nB)J.M. Keynes\nC)AmartyaSen\nD)Carincross",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==13)
		{printf("Question-%d:The famous book “The General Theory of Employment, Interest and Money” is written by\nA)J.B.Say\nB)J.M. Keynescorrect\nC)AmartyaSen\nD)Carincross",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==14)
		{printf("Question-%d:David Copperfield is the name of a\nA)Famous Actor\nB)Novelcorrect\nC)Poemwrong\nD)Writer",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

     if(r==15)
		{printf("Question-%d:Who wrote the famous book - 'We the people'?\nA)T.N.Kaul\nB)J.R.D. Tatawrong\nC)Khushwant Singh\nD)Nani Palkhivala",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==16)
		{printf("Question-%d:“Asian Drama” by Gunnar Karl Mydral is a book on which of the following subjects?\nA)Theatre Movements in Asia\nB)Economics\nC)International Politics\nD)Look East Policy of India",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

     if(r==17)
		{printf("Question-%d:Name the author of the book A Passage to England:\nA)Vikram Seth\nB)Eric Segal\nC)E.M. Forster\nD)Nirad C. Choudhury",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==18)
		{printf("Question-%d:The author of the book “Zest for Life” is?\nA)Mark Twai\nB)Virginia Wol\nC)H.G. Walls\nD)Emile Zola",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==19)
		{printf("Question-%d:Arunima Sinha is author of ________.\nA)Born Again on the Mountain\nB)Lost and Found in India\nC)Forge your Future\nD)Water in the coming Decades",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==20)
		{printf("Question-%d:Which of the following is written by Richard Flanagan\nA)The Narrow Road to the Deep North\nB)Kiran Bedi — Kaise Bani Top Cop\nC)Flood of Fire\nD)Family Life",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==21)
		{printf("Question-%d:Which of the following is written by Natwar Singh?\nA)My Unforgettable Memories\nB)Narendra Modi: A Political Biography\nC)One Life is Not Enough\nD)One Life is Not Enough",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==22)
		{printf("Question-%d:Who is the author of Devadas?\nA)Indira Gandhi\nB)Manu\nC)Ravindra Nath Tagore\nD)Sarat Chandra Chatterjee",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==23)
		{printf("Question-%d:Who wrote the famous book,'Who wants to be a millionaire'?\nA)Vikram Seth\nB)Chetan Bhagat\nC)Agatha Christie\nD)D.Emile Zola",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==24)
		{printf("Question-%d:The autobiography 'Living History' has been authored by\nA)Margaret Atwood\nB)Benazir Bhutto\nC)Hilary Clinton\nD)Monica Lewinsky",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==25)
		{printf("Question-%d:Who wrote the book 'My truth'?\nA)jackie chan\nB)Jawaharlal Nehru\nC)Indira Gandhi\nD)Vijay Hazare",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==26)
		{printf("Question-%d:Who is the author of the book 'Innovation in India'?\nA)Shyam V. Ramani\nB)Arun Kumar\nC)Meenakshi Chaudhary\nD)A.G. Nurani",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==27)
		{printf("Question-%d:Who is the author of the book 'One life is not Enough'?\nA)Prabir De\nB)Natwar Singh\nC)Leema Dhar\nD)Salman Rushdie",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==28)
		{printf("Question-%d:'The Naked Face', a very popular book is written by\nA)Dominique Lapierr\nB)Larry Collins\nC)Sidney Sheldon\nD)Juan Benet",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==29)
		{printf("Question-%d:The first history book was written by\nA)Euclid\nB)Herodotus\nC)Aristotle\nD)Julius Caesar",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==30)
		{printf("Question-%d:Who said 'Man is a political animal'?\nA)Dante\nB)Aristotle\nC)Socrates\nD)Plato",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==31)
		{printf("Question-%d:Who directed the film 'Little Buddha'?\nA)Richard Attenborough\nB)Bernardo Bertolucci\nC)Ben Johnson\nD)Mani Kaul",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==32)
		{printf("Question-%d:Who is the author of 'Tom Sawyer'?\nA)Leo Tolstoy\nB)Mark Twain\nC)John Ruskin\nD)William Shakespeare",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==33)
		{printf("Question-%d:Who said the words,'I disapprove of what you say, but I will defend to Death your right to say it'?\nA)George Bernard Shaw\nB)Lenin\nC)Voltaire\nD)Mahatma Gandhi",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==34)
		{printf("Question-%d:Which of the following books is written by Rabindranath Tagore?\nA)Rakta Karabi\nB)Chidambara\nC)Anand Math\nD)Durgesh Nandini",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==35)
		{printf("Question-%d:The celebrated novel 'The Godfather' was authored by\nA)Harold Robbins\nB)John Milton\nC)Victor Hugo\nD)Mario Puzo",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==36)
		{printf("Question-%d:Who is the author of 'Betrayal of the Defence Forces'?\nA)Vishnu Bhagat\nB)Tarun Tejpal\nC)George Fernandes\nD)Jaswant Singh",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==37)
		{printf("Question-%d:'Crime and Punishment' was written by\nA)Fyodor Dostoevsky\nB)Vladimir Nabakov\nC)Lewis Carrol\nD)Alexander Solzhenitsyn",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==38)
		{printf("Question-%d:Lala Lajpat Rai is the author of the book\nA)India Divided\nB)Unhappy India\nC)Mother India\nD)Hind Swaraj",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==39)
		{printf("Question-%d:Who is the author of 'Ashtadhyayi'?\nA)Sumitranandan\nB)Raj Anand\nC)Panini\nD)Gitta Piramal",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

    if(r==40)
		{printf("Question-%d:Who directed the world famous film 'The Gandhi'?\nA)Ben Kingsley\nB)Satyajit Ray\nC)Mrinal Sen\nD)Richard Attenborough",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}

	}
	printf("Your score is %d out of 10",score);
     
     hs=fopen("highscore.txt","ab");
     fprintf(hs,"\n%s --> %d",name,score);
     fclose(hs);
    printf("\nPress Enter to return Main Menu");
     getch();
     system("cls");
     goto menu;
    break;
	
    
    case 4:
		
	srand(time(NULL));

    for(count=0;count<10;count++){
        array[count]=rand()%40+0;
    }

    while(i<10){
        int r=rand()%40+1;

        for (x = 0; x < i; x++)
        {
            if(array[x]==r){
                break;
            }
        }
        if(x==i){
            array[i++]=r;
        }
    }
    for(p=0;p<10;p++)
	{
        int r=array[p];	
        
        
     if(r==1)
		{printf("Question-%d:Which cricket team has won the 2019-20 Vijay Hazare Trophy?\nA)Karnataka\nB)Gujarat\nC)Jharkhand\nD)Tamil Nadu",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    

    if(r==2)
		{printf("Question-%d:Ryder cup is related to which sports?\nA)Polo\nB)Golf\nC)Tennis\nD)Lawn Tennis",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==3)
		{printf("Question-%d:Who among the following is the First Indian Women to get an Olympic Medal?\nA)Anju Bobby George\nB)Karnam Malleshwari\nC)P T Usha\nD)Nameirakpam Kunjarani",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==4)
		{printf("Question-%d:The ”Marquess of Queensberry rules” is a code of generally accepted rules in which of the following sports?\nA)Chess\nB)Boxing\nC)Hockey\nD)Tennis",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==5)
		{printf("Question-%d:Ezra Cup is related to which of the following sports?\nA)Polo\nB)Tennis\nC)Lawn Tennis\nD)Cricket",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==6)
		{printf("Question-%d:Who among the following cricketers was the first to score a century for the Indian Test cricket team in his Debut Test match ?\nA)Sunil Gawaskar\nB)Kapil Dev\nC)Lala Amarnath\nD)Nawab Pataudi",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==7)
		{printf("Question-%d:Who among the following is first Indian to win an individual gold medal at any Olympic Games?\nA)Abhinav Bindra\nB)Muhammad Aslam\nC)Rajyavardhan Singh Rathode\nD)Mohammed Shahid",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==8)
		{printf("Question-%d:When was the SFI founded?\nA)1975\nB)1948\nC)1956\nD)1979",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==9)
		{printf("Question-%d:Who is the most successful boxer in the World Amateur Boxing Championships in men?\nA)Roberto Balado\nB)Felix Savon\nC)Zou Shiming\nD)Adolfo Horta",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==10)
		{printf("Question-%d:Where are the headquarters of FIAC located?\nA)Geneva\nB)Rome\nC)Bonn\nD)Paris",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==11)
		{printf("Question-%d:Who among the following was first Rajiv Gandhi Khel Ratna?\nA)Viswanathan Anand\nB)Geet Sethi\nC)Karnam Malleswari\nD)Nameirakpam Kunjarani",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==12)
		{printf("Question-%d:Which of the following is not the main sponsor of UEFA Champions League?\nA)Apple\nB)Nissan\nC)Gazprom\nD)MasterCard",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==13)
		{printf("Question-%d:How far is the service line from the net in tennis?\nA)25 feet\nB)21 feet\nC)20 feet\nD)19 feet",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
      
    if(r==14)
		{printf("Question-%d:Who is the captain of Indian National Football team?\nA)Sunil Chhetri\nB)Gurpreet Singh Sandhu\nC)Sandesh Jhingan\nD)Jeje Lalpekhlua",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==15)
		{printf("Question-%d:Which type of shooting championships were discontinued in 1991?\nA)300m rifle\nB)Shotgun\nC)Running Target\nD)Special Airgun championships",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}} 
      
    if(r==16)
		{printf("Question-%d:Who is the 2018 WBC World Heavyweight Champion male?\nA)Anthony Joshua\nB)Deontay Wilder\nC)David Benavidez\nD)Jermell Charlo",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==17)
		{printf("Question-%d:How many teams had participated in the 2018 Women’s Hockey World Cup?\nA)11\nB)8\nC)16\nD)20",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==18)
		{printf("Question-%d:Where did the first UCI Mountain Bike World Championships take place?\nA)United States\nB)Italy\nC)France\nD)Germany",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==19)
		{printf("Question-%d:Who is the President of World Chess Federation?\nA)Alexander Rueb\nB)Max Euwe\nC)Kirsan Ilyumzhinov\nD)Arkady Dvorkovich",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==20)
		{printf("Question-%d:Which nation won the maximum number of medals in the 2018 ISSF World Shooting Championships?\nA)Sweden\nB)Finland\nC)United States\nD)China",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==21)
		{printf("Question-%d:Who was appointed by the then IOC President, Juan Samaranch to lead the initiative as Chairman of the ‘New Sources of Finance Commission’?\nA)Richard Pound\nB)Michael Payne\nC)Avery Brundage\nD)Timo Lumme",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==22)
		{printf("Question-%d:Who had first conceived the idea of a Hockey World Cup?\nA)Patrick Rowley\nB)Nur Khan\nC)Abdul Hafeez Kardar\nD)Bashir Moojid",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==23)
		{printf("Question-%d:Who had opened the 2018 Asian Games officially?\nA)Joko Widodo\nB)Ahmad Al-Fahad Al-Sabah\nC)Susi Susanti\nD)Arki Dikania Wisnu",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==24)
		{printf("Question-%d:When was the first time the Commonwealth Games were held in Asia?\nA)1994\nB)1998\nC)1990\nD)1986",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==25)
		{printf("Question-%d:Which was the Mascot in the UEFA France 2016?\nA)Slavek abd Slavko\nB)Trix and Flix\nC)Super Victor\nD)Kinas",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==26)
		{printf("Question-%d:Where is the International Women’s Boxing Hall of Fame based?\nA)Vancouver\nB)New York\nC)Melbourne\nD)Montreal",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==27)
		{printf("Question-%d:Which of the following nations won their first ever medal at the Commonwealth Games at Gold Coast 2018?\nA)England\nB)India\nC)Solomon Islands\nD)Australia",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==28)
		{printf("Question-%d:Who won the Gold Medal in the 2017 London World Championships in Athletics in the Men’s Pole Vault?\nA)Shawnacy Barber\nB)Sam Kendricks\nC)Piotr Lisek\nD)Renaud Lavillenie",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==29)
		{printf("Question-%d:What should be the standard weight of the cricket ball?\nA)Between 6 and 7 ounces\nB)Between 5 and 6 ounces\nC)Between 7 and 8 ounces\nD)Between 8 and 9 ounces",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==30)
		{printf("Question-%d:Where was the second 2018 Junior World Cup held?\nA)Russia\nB)Australia\nC)Germany\nD)Italy",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
    
    if(r==31)
		{printf("Question-%d:In which boxing championship are the boxers required to compete with each other bare-chested and without protective headgear?\nA)AIBA World Boxing championships\nB)AIBA World Series of Boxing\nC)Olympics\nD)Boxing World Cup",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
      
    if(r==32)
		{printf("Question-%d:Who is the Coach of India Women’s National Hockey Team?\nA)Sjoerd Marijine\nB)Erik Wonink\nC)Kumar\nD)R. Femke Koojiman",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==33)
		{printf("Question-%d:Who had won the 2018 Downhill World Cup for men?\nA)Aaron Gwin\nB)Sam Hill\nC)Steve Peat\nD)Amaury Pierron",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
        
    if(r==34)
		{printf("Question-%d:Who won the Gold Medal in Pole Vaulting in men’s category in 2016 Rio Olympics?\nA)Sam Kendricks\nB)Renaud Lavillenie\nC)Thiago Braz da Silva\nD)Raphael Holzdeppe",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==35)
		{printf("Question-%d:Who is the Vice President of International Paralympic Committee?\nA)Andrew Parsons\nB)Duane Kale\nC)Robert Steadward\nD)Philip Craven",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==36)
		{printf("Question-%d:Which country is going to host FIFA World Cup 2022?\nA)Qatar\nB)France\nC)Italy\nD)Argentina",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==37)
		{printf("Question-%d:Who is the manager of India Men’s National Hockey team?\nA)Harendra Singh\nB)Arjun Halappa\nC)Manpreet Singh\nD)Harmanpreet Singh",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==38)
		{printf("Question-%d:Which Indian pair broke the record for the longest tie-break against the Uzbek pair Vlada Ekshibarova and Ivanna Israilova?\nA)Sania Mirza and Ankita Raina\nB)Ankita Raina and Manisha Malhotra\nC)Pranjala Yadlapalli and Manisha Malhotra\nD)Sania Mirza and Manisha Malhotra",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==39)
		{printf("Question-%d:When was the first international match of women’s cricket played?\nA)1897\nB)1908\nC)1888\nD)1934",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==40)
		{printf("Question-%d:Who is the President of Badminton World Federation?\nA)John McCallum\nB)David Bloomer\nC)Poul-Erik Hoyer Larsen\nD)Stellan Mohin",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
         
        }   
    


    printf("Your score is %d out of 10",score);
 hs=fopen("highscore.txt","ab");
   
     fprintf(hs,"\n%s --> %d",name,score);
     fclose(hs);
    printf("\nPress Enter to return Main Menu");
     getch();
     system("cls");
     goto menu;
    break;
    
    case 5:
	
    
    
    srand(time(NULL));

    for(count=0;count<10;count++){
        array[count]=rand()%40+0;
    }

    while(i<10){
        int r=rand()%40+1;

        for (x = 0; x < i; x++)
        {
            if(array[x]==r){
                break;
            }
        }
        if(x==i){
            array[i++]=r;
        }
    }
    for(p=0;p<10;p++)
	{
        int r=array[p];	
        
        
     if(r==1)
		{printf("Question-%d:Brass gets discoloured in air because of the presence of which of the following gases in air?\nA)Oxygen\nB)Hydrogen sulphide\nC)Carbon dioxide\nD)Nitrogen",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    

    if(r==2)
		{printf("Question-%d:Which of the following is a non metal that remains liquid at room temperature?\nA)Phosphorous\nB)Bromine\nC)Chlorine\nD)Helium",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==3)
		{printf("Question-%d:Chlorophyll is a naturally occurring chelate compound in which central metal is\nA)copper\nB)magnesium\nC)iron\nD)calcium",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==4)
		{printf("Question-%d:Which of the following is used in pencils?\nA)Graphite\nB)Silicon\nC)Charcoal\nD)Phosphorous",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==5)
		{printf("Question-%d:Which of the following metals forms an amalgam with other metals?\nA)Tin\nB)Mercury\nC)Lead\nD)Zinc",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==6)
		{printf("Question-%d:The gas usually filled in the electric bulb is\nA)nitrogen\nB)hydrogen\nC)carbon dioxide\nD)oxygen",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==7)
		{printf("Question-%d:Washing soda is the common name for\nA)Sodium carbonate\nB)Calcium bicarbonate\nC)Sodium bicarbonate\nD)Calcium carbonate",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==8)
		{printf("Question-%d:Quartz crystals normally used in quartz clocks etc. is chemically\nA)silicon dioxide\nB)germanium oxide\nC)a mixture of germanium oxide and silicon dioxide\nD)sodium silicate",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==9)
		{printf("Question-%d:Which of the gas is not known as green house gas?\nA)Methane\nB)Nitrous oxide\nC)Carbon dioxide\nD)Hydrogen",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==10)
		{printf("Question-%d:Bromine is a\nA)black solid\nB)red liquid\nC)colourless gas\nD)highly inflammable gas",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==11)
		{printf("Question-%d:The hardest substance available on earth is\nA)Gold\nB)Iron\nC)Diamond\nD)Platinum",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==12)
		{printf("Question-%d:The variety of coal in which the deposit contains recognisable traces of the original plant material is\nA)bitumen\nB)anthracite\nC)lignite\nD)peat",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==13)
		{printf("Question-%d:Tetraethyl lead is used as\nA)pain killer\nB)fire extinguisher\nC)mosquito repellent\nD)petrol additive",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
      
    if(r==14)
		{printf("Question-%d:Which of the following is used as a lubricant?\nA)Graphite\nB)Silica\nC)Iron Oxide\nD)Diamond",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==15)
		{printf("Question-%d:The inert gas which is substituted for nitrogen in the air used by deep sea divers for breathing, is\nA)Argon\nB)Xenon\nC)Helium\nD)Krypton",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}} 
      
    if(r==16)
		{printf("Question-%d:The gases used in different types of welding would include\nA)oxygen and hydrogen\nB)oxygen, hydrogen, acetylene and nitrogen\nC)oxygen, acetylene and argon\nD)oxygen and acetylene",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==17)
		{printf("Question-%d:The property of a substance to absorb moisture from the air on exposure is called\nA)osmosis\nB)deliquescence\nC)efflorescence\nD)desiccation",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==18)
		{printf("Question-%d:In which of the following activities silicon carbide is used?\nA)Making cement and glass\nB)Disinfecting water of ponds\nC)cutting very hard substances\nD)Making casts for statues",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==19)
		{printf("Question-%d:The average salinity of sea water is\nA)3%\nB)3.5%\nC)2.5%\nD)2%",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==20)
		{printf("Question-%d:When an iron nail gets rusted, iron oxide is formed\nA)without any change in the weight of the nail\nB)with decrease in the weight of the nail\nC)with increase in the weight of the nail\nD)without any change in colour or weight of the nail",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==21)
		{printf("Question-%d:Galvanised iron sheets have a coating of\nA)lead\nB)chromium\nC)zinc\nD)tin",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==22)
		{printf("Question-%d:Among the various allotropes of carbon,\nA)coke is the hardest, graphite is the softest\nB)diamond is the hardest, coke is the softest\nC)diamond is the hardest, graphite is the softest\nD)diamond is the hardest, lamp black is the softest",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==23)
		{printf("Question-%d:The group of metals Fe, Co, Ni may best called as\nA)transition metals\nB)main group metals\nC)alkali metals\nD)rare metals",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==24)
		{printf("Question-%d:Heavy water is\nA)deuterium oxide\nB)PH7\nC)rain water\nD)tritium oxide",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==25)
		{printf("Question-%d:The chemical (ethyl mercaptan) added to the otherwise odourless LPG cooking gas for imparting a detectable smell to the gas is a compound of\nA)bromine\nB)fluorine\nC)chlorine\nD)sulphur",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==26)
		{printf("Question-%d:The element common to all acids is\nA)hydrogen\nB)carbon\nC)sulphur\nD)oxygen",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==27)
		{printf("Question-%d:Non stick cooking utensils are coated with\nA)Teflon\nB)PVC\nC)black paint\nD)polystyrene",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==28)
		{printf("Question-%d:Monazite is an ore of\nA)titanium\nB)zirconium\nC)iron\nD)thorium",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==29)
		{printf("Question-%d:Carbon, diamond and graphite are together called\nA)allotropes\nB)isomers\nC)isomorphs\nD)isotopes",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==30)
		{printf("Question-%d:Potassium nitrate is used in\nA)medicine\nB)fertiliser\nC)salt\nD)glass",p+1);
        if(toupper(getch()) == 'B')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
    
    if(r==31)
		{printf("Question-%d:Permanent hardness of water may be removed by the addition of\nA)sodium carbonate\nB)alum\nC)potassium permanganate\nD)lime",p+1);
        if(toupper(getch()) == 'A')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
      
    if(r==32)
		{printf("Question-%d:Soda water contains\nA)carbonic acid\nB)sulphuric acid\nC)carbon dioxide\nD)nitrous acid",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
      
    if(r==33)
		{printf("Question-%d:The most important ore of aluminium is\nA)galena\nB)calamine\nC)calcite\nD)bauxite",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}  
        
    if(r==34)
		{printf("Question-%d:Most soluble in water is\nA)camphor\nB)sulphur\nC)common salt\nD)sugar",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==35)
		{printf("Question-%d:Which of the following was to be discovered first in the chromospheres of the sun?\nA)Krypton\nB)Xenon\nC)Neon\nD)Helium",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==36)
		{printf("Question-%d:Which of the following is in liquid form at room temperature?\nA)Lithium\nB)Sodium\nC)Francium\nD)Cerium",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==37)
		{printf("Question-%d:Sodium metal is kept under\nA)petrol\nB)alcohol\nC)water\nD)kerosene",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==38)
		{printf("Question-%d:Which of the following are the ingredients of gun metal?\nA)Iron, Zinc, Titanium\nB)Iron, tin\nC)Iron, Brass, Tin\nD)Copper, Tin",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==39)
		{printf("Question-%d:From which mineral is radium obtained?\nA)Rutile\nB)Haematite\nC)Limestone\nD)Pitchblende",p+1);
        if(toupper(getch()) == 'D')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
        
    if(r==40)
		{printf("Question-%d:Actinides are the elements with atomic numbers from\nA)97 to 104\nB)101 to 115\nC)89 to 103\nD)36 from 43",p+1);
        if(toupper(getch()) == 'C')
        {score++;
        system("cls");
        }
        else{
        system("cls");
        continue;}}    
         
        }   
    


    printf("Your score is %d out of 10",score);

     hs=fopen("highscore.txt","ab");
    
     fprintf(hs,"\n%s --> %d",name,score);
     fclose(hs);
     
   printf("\nPress Enter to return Main Menu");
     getch();
     system("cls");
     goto menu;  
break;
    
    


}

return 0;
 


 
}
