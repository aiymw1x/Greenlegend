import cv2
import serial
from ultralytics import YOLO

model = YOLO(r'C:\Users\Inkar\Desktop\yolov5s.pt')


cap = cv2.VideoCapture(0)


confidence_threshold = 0.5

try:
    ser = serial.Serial('COM8', 9600)  
except serial.SerialException as e:
    print(f"Error: {e}")
    print("Could not open port COM5. Please check the port and try again.")
    exit() 

target_classes = ['cup', 'bottle']

while True:
    
    ret, frame = cap.read()

   
    if not ret:
        break

    
    frame_height, frame_width = frame.shape[:2]
    quarter_width = frame_width // 4

    
    cv2.line(frame, (quarter_width, 0), (quarter_width, frame_height), (255, 255, 255), 2)      # 1st vertical line
    cv2.line(frame, (2 * quarter_width, 0), (2 * quarter_width, frame_height), (255, 255, 255), 2)  # 2nd vertical line
    cv2.line(frame, (3 * quarter_width, 0), (3 * quarter_width, frame_height), (255, 255, 255), 2)  # 3rd vertical line

    
    results = model(frame)

    detected_target = False

    
    for result in results:
        boxes = result.boxes.xyxy.cpu().numpy()  
        confs = result.boxes.conf.cpu().numpy()
        clses = result.boxes.cls.cpu().numpy()   

        for box, conf, cls in zip(boxes, confs, clses):
            if conf >= confidence_threshold:
                class_name = model.names[int(cls)]
                if class_name in target_classes:
                    detected_target = True

                    x1, y1, x2, y2 = map(int, box)
                    box_width = x2 - x1
                    box_height = y2 - y1

                    
                    center_x = (x1 + x2) // 2

                    if center_x < quarter_width:
                        position = 1  
                    elif center_x < 2 * quarter_width:
                        position = 2 
                    elif center_x < 3 * quarter_width:
                        position = 3  
                    else:
                        position = 4  

                    
                    if box_width * box_height >= 0.9 * frame_width * frame_height:
                        ser.write('5'.encode())  
                    else:
                        ser.write(str(position).encode())  

                   
                    label = f"{class_name} {conf:.2f}"
                    cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
                   
                    cv2.putText(frame, label, (x1, y1 - 10 if y1 > 20 else y1 + 20), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)
                else:
                    continue

    if not detected_target:
        ser.write(b'0') 

    
    cv2.imshow('YOLOv8 Real-time Detection', frame)

    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break


cap.release()
cv2.destroyAllWindows()

 
ser.close()

