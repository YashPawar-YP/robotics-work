from ultralytics import YOLO
import cv2
from collections import Counter

model = YOLO("yolov8n.pt")

cap = cv2.VideoCapture("video.mp4")
if not cap.isOpened():
    raise RuntimeError

ls = []
while cap.isOpened():
    success, frame = cap.read()
    if success:
        results = model.track(frame, persist = True)
        for i in results:
            boxes = i.boxes
            for box in boxes:
                class_id = int(box.cls[0])
                class_name = i.names[class_id]
                ls.append(class_name)   
        if cv2.waitKey(1) & 0xFF == ord("q"):
            break
    else:
        break



# ls = []
# for i in img:
#     boxes = i.boxes
#     for box in boxes:
#         class_id = int(box.cls[0])
#         class_name = i.names[class_id]
#         ls.append(class_name)

count = Counter(ls)

print(ls)
for i, j in count.items():
    print(f"{i}: {j}")