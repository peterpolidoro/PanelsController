//.$file${./ArenaControlle~::ArenaController.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: ArenaController.qm
// File:  ${./ArenaControlle~::ArenaController.cpp}
//
// This code has been generated by QM 5.1.3 <www.state-machine.com/qm/>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.
//
//.$endhead${./ArenaControlle~::ArenaController.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^
#include "ArenaController.hpp"  // ArenaController application interface

using namespace QP;

namespace ArduinoInterface {

//............................................................................
void setup() {

    QF::init(); // initialize the framework
    BSP::init(); // initialize the BSP

    // init publish-subscribe
    static QSubscrList subscrSto[AC::MAX_PUB_SIG];
    QF::psInit(subscrSto, Q_DIM(subscrSto));

   // statically allocate event queues for the AOs and start them...
    static QEvt const *serial_command_interface_queueSto[10];
    AC::AO_SerialCommandInterface->start(1U, // priority
        serial_command_interface_queueSto, Q_DIM(serial_command_interface_queueSto),
        (void *)0, 0U); // no stack

    static QEvt const *ethernet_command_interface_queueSto[10];
    AC::AO_EthernetCommandInterface->start(2U, // priority
        ethernet_command_interface_queueSto, Q_DIM(ethernet_command_interface_queueSto),
        (void *)0, 0U); // no stack

    static QEvt const *arena_queueSto[10];
    AC::AO_Arena->start(3U, // priority
        arena_queueSto, Q_DIM(arena_queueSto),
        (void *)0, 0U); // no stack

    static QEvt const *display_queueSto[10];
    AC::AO_Display->start(4U, // priority
        display_queueSto, Q_DIM(display_queueSto),
        (void *)0, 0U); // no stack

    //static QEvt const *frame_queueSto[10];
    //AC::AO_Display->start(5U, // priority
    //    frame_queueSto, Q_DIM(frame_queueSto),
    //    (void *)0, 0U); // no stack

   //...
}

//............................................................................
void loop() {
    QF::run(); // run the QF/C++ framework
}

} // namespace AC