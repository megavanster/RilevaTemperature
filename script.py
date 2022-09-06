import serial
import sys
import time
import string


# apro e inizializzo la seriale
output = " "
port = "/dev/ttyACM0"
baud = 9600

ser = serial.Serial( port, baud, 8, 'N', 1, timeout = 1)

while 1:
	# print ('.')
	while output != "":
		output = ser.readline()
		if output != "":
			t = time.strftime("%H:%M:%S") 
			output =  t + ';' + output
			print (output)

			# apro un file in write mode
			t = time.strftime("%Y%m%d")
			t = 'ril_' + t + '.csv'
			fo = open( t , "a")
			print "Name of the file> ", fo.name

			fo.write(output)
			fo.close()
	output = " "




