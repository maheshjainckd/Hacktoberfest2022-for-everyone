import cv2
import numpy as np
import pyautogui as p

rs = p.size()

fn = input("Enter the location where you want to store file:")

fps = 10.0

fourcc= cv2.VideoWriter_fourcc(*'XVID')
output = cv2.VideoWriter(fn, fourcc, fps, rs)

cv2.namedWindow("Live_Rec",cv2.WINDOW_NORMAL)

cv2.resizeWindow("Live_Rec", (600,400))

while True:
    img = p.screenshot()
    f = np.array(img)
    f = cv2.cvtColor(f, cv2.COLOR_BGR2RGB)
    output.write(f)
    
    cv2.imshow("Live_Rec", f)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
output.release()    
cv2.destroyAllWindows()    


