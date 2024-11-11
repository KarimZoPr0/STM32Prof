import serial
import time

# Serial port configuration
SERIAL_PORT = 'COM5'
BAUD_RATE = 115200

# Unique reset message from MCU
RESET_MESSAGE = b'MCU_RESET\n'

LOG_FILE_NAME = 'STM32Prof.spall'

def main():
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        print(f'Connected to serial port: {SERIAL_PORT}')
    except serial.SerialException as e:
        print(f'Error opening serial port {SERIAL_PORT}: {e}')
        return

    log_file = None

    try:
        while True:
            line = ser.readline()
            if line:
                if RESET_MESSAGE in line:
                    print('Reset message detected.')
                    if log_file:
                        log_file.close()
                        print('Closed current log file.')

                    log_file = open(LOG_FILE_NAME, 'wb')
                    print(f'Started new log file: {LOG_FILE_NAME}')
                else:
                    if log_file:
                        log_file.write(line)
                        log_file.flush()
            else:
                time.sleep(0.01)
    except KeyboardInterrupt:
        print('Logging stopped by user.')
    finally:
        if log_file:
            log_file.close()
            print('Closed log file.')
        ser.close()
        print('Serial port closed.')

if __name__ == '__main__':
    main()
