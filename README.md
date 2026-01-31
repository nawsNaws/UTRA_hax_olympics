🤖 UTRA Hacks 2026: The Track Master
Welcome to the official repository for our UTRA Hacks competition robot!
This bot is engineered to navigate a complex track, identify color-coded signals, and interact with objects using a precision claw.Our robot is a multi-sensory powerhouse designed for speed, accuracy, and object manipulation:

Line Following: Dual IR sensors for high-speed navigation along the track.Obstacle Avoidance: HC-SR04 Ultrasonic sensor for real-time distance mapping.Color Detection: TCS3200 Color Sensor to trigger specific behaviors based on track markers.

Object Manipulation: A custom-mounted mini-servo claw for "pick and place" challenges.Drivetrain: Two high-torque DC motors powered by an L298N H-Bridge driver.🛠 Hardware SpecificationsComponentPurposePins (Example)

MicrocontrollerLogic & ProcessingArduino Uno / ESP32HC-SR04Ultrasonic Distance SensingTrig: D9, Echo: D10IR Sensors (x2)Line Following (Left/Right)D2, D3TCS3200Color IdentificationS0-S3, Out: D4-D8Mini ServoClaw ActuationD11 (PWM)DC MotorsDifferential SteeringD5, D6 (PWM)💻 Logic FlowCalibration: On startup, the robot calibrates IR thresholds and color white-balancing.Navigation: The robot follows the black line. If the Ultrasonic sensor detects an object within a safety threshold, it halts.Color Check: Upon hitting a color patch (e.g., Red), the robot executes a specific script (e.g., "Deploy Claw").

Action: The Servo engages to grab the payload, and the robot continues the track.
