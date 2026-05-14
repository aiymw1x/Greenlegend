# # GreenLegend: Autonomous Forest Restoration & Cleanup
GreenLegend is an integrated robotics project designed to address the critical issue of deforestation and environmental pollution. By combining hardware control via Arduino with state-of-the-art computer vision, GreenLegend automates the process of planting seedlings and removing hazardous waste from natural habitats.

🤖 Hardware Control (Arduino)
humidity/: Manages soil moisture sensing to ensure seedlings are planted in viable conditions.
Inkar/: Contains the core logic for the seedling planting mechanism.
sbor_mysora/: Handles the mechanical operation of the garbage collection system.

🧠 Computer Vision (Python & YOLOv5)
The project utilizes the YOLOv5 architecture for real-time object detection and spatial awareness:
realtime_obstacles.py: Processes live video feeds to identify and navigate around trees, rocks, and uneven terrain.
realtime_garbage.py: Specifically trained to detect various types of litter for autonomous retrieval.
yolov5s.pt: The pre-trained weights file used to power the neural networks.

🛠 Core Functionalities
Precision Reforestation: Automates the labor-intensive task of planting seedlings to speed up forest recovery.
Intelligent Waste Removal: Identifies and collects inorganic trash to restore soil health and protect local ecosystems.
Smart Navigation: Uses neural networks to safely maneuver through complex, unstructured forest environments without human intervention.
