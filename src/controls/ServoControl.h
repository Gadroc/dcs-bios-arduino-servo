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
#ifndef _DCSBIOS_SERVOS_H_
#define _DCSBIOS_SERVOS_H_

#include <Arduino.h>
#include <Servo.h>
#include "dcs/IntegerListener.h"

class ServoOutput : IntegerListener {
private:
    Servo _servo;
    const int _minPulseWidth;
    const int _maxPulseWidth;

    unsigned int _lastValue;

public:
    ServoOutput(unsigned int address, unsigned int mask, uint8_t shift, int minPulseWidth = 540, int maxPulseWidth = 2400);
    void attach(uint8_t pin);

    void onDcsBiosFrameSync() override;
};

#endif