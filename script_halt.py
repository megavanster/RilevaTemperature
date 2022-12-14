# Simple script for shutting down the raspberry Pi at the press of a button.
# add to /etc/rc.d or crontab

import RPi.GPIO as GPIO
import time
import os

# Use the Broadcom SOC Pin numbers
# Setup the Pin with Internal pullups enabled and PIN in reading mode.
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(26, GPIO.IN, pull_up_down = GPIO.PUD_UP)

# Our function on what to do when the button is pressed
def Shutdown(channel):
  os.system("sudo shutdown -h now")

# Add our function to execute when the button pressed event happens
GPIO.add_event_detect(26, GPIO.FALLING, callback = Shutdown, bouncetime = 2000)

# Now wait!
while 1:
 time.sleep(1)