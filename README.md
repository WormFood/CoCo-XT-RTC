# Burke & Burke CoCo XT-RTC with OS-9 Boot ROM.

Back in the day, accessories for the IBM PC were dirt cheap, compared to
other computer systems. Most hard drive intefaces for the CoCo were quite
expensive. That's where the CoCo XT-RTC comes into play. This adapter
allows you to plugin a standard Western Digital HDD controller, designed
for the IBM PC, into the CoCo.

Included is the 8K boot ROM (both scrambled and unscrambled) that plugs into
the HDD controller, and allows the CoCo to boot directly into OS-9. If you
add +12v (7812 works) to pin 2 on the cartridge port, then you can plug the
CoCo XT-RTC directly into the CoCo 3's cartridge port, without the need for
a multi-pack interface.

I have no way to validate the integrity of this ROM file, but this is what I
have burned into my EPROM. Please note, that this rom is "scrambled", so you
can't make much sense out of it, without knowing how it is scrambled. Address
lines A4, A5 and A6 are inverted, so it's trivial to unscramble. Also included
is the software to scramble or unscramble the ROM image.

Text found within the ROM file, suggests that the game of life built-in to it,
but I haven't investigated it, to see how to activate it.

I made the schematics real quick, and did a reasonable amount of double checking,
but it is still possible I could have made a mistake. Everything looks reasonable,
except for the one thing I noted on the schematics.

![Burke & Burke CoCo XT RTC](/Pictures/Burke_and_Burke_CoCo_XT-RTC_external.jpg "Burke & Burke CoCo XT RTC")

A closeup view of the PCB. Notice the "MADE IN USSR" 7400 ICs. The battery was never replaced, and has about 2.9 volts in 2025.
![Burke & Burke CoCo XT RTC PCB](/Pictures/Burke_and_Burke_CoCo_XT-RTC_PCB.jpg "Burke & Burke CoCo XT RTC PCB")

The CoCo XT-RTC with a WD1002-WX1 and OS-9 boot ROM installed.
![Burke & Burke CoCo XT RTC W/WD1002-WX1](/Pictures/Burke_and_Burke_CoCo_XT-RTC_with_WD1002-WX1.jpg "Burke & Burke CoCo XT RTC w/WD1002-WX1 and OS-9 boot ROM")

The CoCo XT-RTC with a WD1002A-WX1 installed.
![Burke & Burke CoCo XT RTC W/WD1002A-WX1](/Pictures/Burke_and_Burke_CoCo_XT-RTC_with_WD1002A-WX1.jpg "Burke & Burke CoCo XT RTC w/WD1002A-WX1")

This should be accurate.
![Burke & Burke CoCo XT RTC](/Burke_and_Burke_CoCo_XT-RTC_Schematics.png "Burke & Burke CoCo XT RTC")
