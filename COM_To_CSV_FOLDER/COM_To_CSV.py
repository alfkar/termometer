import serial.tools.list_ports 
import csv 
import time
ser = serial.Serial()
ser.port = 'COM3'
ser.baudrate = 9600
ser.open()
ser.flushInput()
''' 
def checkforport(): 
    ser.close()
    while True:
        for port in serial.tools.list_ports.comports():
            if 'COM3' == port.name:
                print(port.name)
                print("Got here")
                ser.port = 'COM3'
                print(ser.port)
                ser.baudrate = 9600
                print("Got here 2")
                ser.open()
                print("Got here 3")
                ser.flushInput()
                return
               
'''

def CSV_write():
    while True:
        try:
            ser_bytes = ser.readline()
            decoded_bytes = ser_bytes[0:len(ser_bytes)-2].decode("utf-8")
            print(decoded_bytes)
            with open("C:/Users/Alfre/Temperaturdata/test_data.csv","a") as f:
                writer = csv.writer(f,delimiter=",")
                writer.writerow([time.time(),decoded_bytes])

        except:
            print("Error reading input")
            break
           # checkforport()

#checkforport()
CSV_write()
        
