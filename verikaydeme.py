import time
import random
import serial
import csv
import datetime

DateTime = 0


rows=0

Acc_X = 0
Acc_Y = 0
Acc_Z = 0
Gyr_X = 0
Gyr_Y = 0
Gyr_Z = 0
Pressure = 0
Altitude = 0
Nem = 0
sicaklik = 0
Long = 0
Lat = 0
hiz = 0

ser = serial.Serial("COM6",115200, timeout=0.02)

#csv dosyasının başlığı
with open('Car_data.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    field = ["Acc_X", "Acc_Y", "Acc_Z", "Gyr_X", "Gyr_Y", "Gyr_Z", "Pressure", "Altitude", "Nem", "sicaklik",
             "Longitude", "Latitude", "Hiz","Zaman_saat",]
    writer.writerow(field)

while(True):    
    data = ser.readline()
    data = data.decode()
    if data:
        rows = [x for x in data.split(',')]
        Acc_X = rows[0]
        Acc_Y = rows[1]
        Acc_Z = rows[2]
        Gyr_X = rows[3]
        Gyr_Y = rows[4]
        Gyr_Z = rows[5]
        Pressure = rows[6]
        Altitude = rows[7]
        Nem = rows[8]
        sicaklik = rows[9]
        Long = rows[10]
        Lat = rows[11]
        hiz  = rows[12]

        Zaman_saat = datetime.datetime.now()

        with open('Aviyonik_data.csv', 'a+', newline='') as file:
            writer = csv.writer(file)
            writer.writerow([Acc_X, Acc_Y, Acc_Z, Gyr_X, Gyr_Y, Gyr_Z, Pressure, Altitude, Nem, sicaklik,Long, Lat, hiz,Zaman_saat,])
    print(rows)