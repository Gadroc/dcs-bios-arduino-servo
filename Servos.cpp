/*
	Copyright 2015 Craig Courtney

    This file is part of DcsBios-Firmware.

    DcsBios-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DcsBios-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with DcsBios-Firmware.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "Servos.h"

ServoOutput::ServoOutput(uint8_t address, unsigned int minPulseWidth, unsigned int maxPulseWidth) {
    _address = address;
    _minPulseWidth = minPulseWidth;
    _maxPulseWidth = maxPulseWidth;
}

void ServoOutput::begin(uint8_t pin) {
    _servo.attach(pin, _minPulseWidth, _maxPulseWidth);
    _servo.writeMicroseconds(_minPulseWidth);
    _lastValue = _minPulseWidth;
}

void ServoOutput::onBufferReady(uint8_t *buffer) {
    unsigned int data = (buffer[_address] << 8) | buffer[_address+1];
    unsigned int value = map(data, 0, 65535, _minPulseWidth, _maxPulseWidth);
    if (_lastValue != value) {
        _servo.writeMicroseconds(value);
        _lastValue = data;
    }
}