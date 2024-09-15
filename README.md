# Wall Follower Robot

This project implements a simple wall-following robot using an Arduino Uno. The robot navigates through a predefined maze layout, following the walls and checkpoints until it reaches the finish line.

## Pin Configuration

- **M11**: Pin 9 (Motor 1 forward)
- **M12**: Pin 10 (Motor 1 reverse)
- **M21**: Pin 5 (Motor 2 forward)
- **M22**: Pin 6 (Motor 2 reverse)
- **Trig Pin**: Pin 2 (Trigger for ultrasonic sensor)
- **Echo Pin**: Pin 7 (Echo for ultrasonic sensor)

## Features

1. The robot moves forward until it encounters an obstacle (a wall) based on sensor input.
2. Upon encountering a wall, the robot turns either left or right based on predefined checkpoints.
3. It follows a sequence of turns (left or right) to navigate through the maze.

### Checkpoint Logic:

- **Checkpoint 1**: Turn left.
- **Checkpoint 2**: Turn right.
- **Checkpoint 3**: Turn right.
- **Checkpoint 4**: Turn left.
- **Checkpoint 5**: Turn right.
- **Checkpoint 6**: Turn right.

## Functions

- `comeForward()`: Moves the robot forward by driving both motors forward.
- `turnRight()`: Turns the robot right by reversing one motor and driving the other forward.
- `turnLeft()`: Turns the robot left by reversing one motor and driving the other forward.
- `sensor_ping()`: Uses the ultrasonic sensor to measure the distance to an obstacle.
- `microsecondsToCentimeters()`: Converts the sensor data from microseconds to centimeters.

## Installation

1. Clone the repository to your local machine.
2. Upload the Arduino sketch to your Arduino board.
3. Connect the motors and sensors as per the pin configuration.
4. Power the robot and place it at the starting point of the maze.

## Usage

- Once powered on, the robot will automatically start moving forward.
- It will follow the walls and turn at the predefined checkpoints until it reaches the finish line.

## Notes

- Make sure to adjust the `distance` variable if the sensor sensitivity needs to be tuned.
- The `timeturnRight` and `timeturnLeft` can also be adjusted based on your motor speed and turning dynamics.

## License

This project is open-source and licensed under the MIT License.
