# agaric's Planck layout

**flashing on linux**

1. Make sure `docker` and `dfu-programmer` are installed.

1. Physically poke the little button on the back of the PCB in order to enter *flash-ready* mode.

1. Compile the firmware and flash the keyboard with it.

    ```sh
    $ cd path/to/qmk_firmware
    $ docker run -e keymap=agaric -e subproject=rev4 -e keyboard=planck --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
    $ sudo dfu-programmer atmega32u4 erase --force
    $ sudo dfu-programmer atmega32u4 flash ./.build/planck_rev4_agaric.hex
    $ sudo dfu-programmer atmega32u4 reset
    ```

    See also:
    - https://docs.qmk.fm/build_environment_setup.html
    - https://docs.qmk.fm/faq_build.html
