import serial
import time

PORT = '/dev/cu.usbserial-0285799D'  
BAUD_RATE = 115200
esp32 = serial.Serial(PORT, BAUD_RATE, timeout=1)
try:
    
    # Open the serial connection
    time.sleep(2)  # Wait for ESP32 to initialize

    print("Connected to ESP32. Sending data...")

    while True:
        # Send a message to the ESP32
        message = input("Enter a message to send: ")
        esp32.write((message + '\n').encode())  

        # Wait for a response 
        response = esp32.readline().decode().strip()
        if response:
            print(f"ESP32 Response: {response}")

except serial.SerialException as e:
    print(f"Error: {e}")

finally:
    # Close the serial connection
    if esp32.is_open:
        esp32.close()
        print("Serial connection closed.")
