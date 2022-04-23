/*
 * Copyright (c) 2020-2021 Advanced Robotics at the University of Washington <robomstr@uw.edu>
 *
 * This file is part of Taproot.
 *
 * Taproot is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Taproot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Taproot.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef SHARP_IR_HPP_
#define SHARP_IR_HPP_

#include "analog_distance_sensor.hpp"

namespace tap
{
class Drivers;
namespace sensors
{
/**
 * Basic SHARP IR Sensor via analog input.  Returns distance in cm.
 *
 * The distance conversion can be tweaked depending on the sensor.
 */
class SharpIrGP2Y0A41 : public AnalogDistanceSensor
{
public:
    /**
     * Constructor to init Sharp IR analog pin.
     *
     * @param[in] pin the analog pin to attach the sensor to.
     */
    SharpIrGP2Y0A41(Drivers *drivers, gpio::Analog::Pin pin);

    /**
     * Init not needed for Sharp IR.
     */
    void init() override {}

private:
    /// Min distance boundary value (in cm).
    static constexpr float SHARP_IR_MIN = 4.0f;
    /// Max distance boundary value (in cm).
    static constexpr float SHARP_IR_MAX = 30.0f;

    // Subject to change.
    /// Distance calculation values for SHARP 0A41SK F IR Sensor.
    static constexpr float SHARP_IR_M = 0.072f;
    /// Distance calculation values for SHARP 0A41SK F IR Sensor.
    static constexpr float SHARP_IR_B = -0.008f;
    /// Distance calculation values for SHARP 0A41SK F IR Sensor.
    static constexpr float SHARP_IR_OFFSET = -0.42f;
};  // class SharpIrGP2Y0A41

}  // namespace sensors

}  // namespace tap

#endif  // SHARP_IR_HPP_
