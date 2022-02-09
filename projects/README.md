# SRF projects

## Project-01

Using a button, we count the number of pushes and multiply it by 10.

`distance = buttonPushCount * scale`

The robot travels the distance and then stops.

## Project-02

Put the robot in a distance `x` from the wall. The robot should travel until getting to distance `x - 20` and turn 180 degrees. Then, comes back to the spot in started at.

## Components

- LCD I2C
- L298n motor driver
- SRF

### Videos

Link to project videos:
| project1 | [here](https://www.dropbox.com/s/q17qvg7w8v4bxer/IMG_1930.mp4?dl=0) |
|---|---|
| project2 | [here](https://www.dropbox.com/s/ztivxlrps7c6iag/IMG_1949.mp4?dl=0) |

## Prerequisites

- Arduino IDE
- Arduino Uno
- The component mentioned

## Run locally

Clone the project

`git clone `

> 1. Open `withButton.ino` in `loki/projects` directory in Arduino IDE
> 2. Plug in you Arduino Uno
> 3. Upload the program
