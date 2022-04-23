#include "tap/board/board.hpp"
#include "drivers_singleton.hpp"

int main()
{
    /*
     * NOTE: We are using DoNotUse_getDrivers here because in the main
     *      robot loop we must access the singleton drivers to update
     *      IO states and run the scheduler.
     */
    ::Drivers *drivers = ::DoNotUse_getDrivers();

    Board::initialize();
    drivers->leds.init();

    bool aSet = true; //this variable sets the "A" labeled LED on the board to be on/off

    while (1)
    {
        modm::delay_ms(500); //delay for 500 ms between flipping the LED to on or off
        drivers->leds.set(tap::gpio::Leds::A, !aSet); //sets the LED to either on or off according to aSet
        aSet = !aSet; //toggle aSet
    }
    return 0;
}
