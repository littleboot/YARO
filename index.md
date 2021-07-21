## YARO - Yet Another Reflow Oven
Yet Another Reflow Oven. An open source DIY Reflow Hotplate and general AC load controllercontroller. This project is 100% opensource it includes all files needed to create your own, in addition I have documented the design decissions which might be usefull. 
### Result
Let's start with some pictures. A picture is worth a thousand words so this saves me a lot of typing :).

**Reflow oven**
![Reflow oven photo front](/Images/Reflow_oven_photo_1.png)
![Reflow oven photo back](/Images/Reflow_oven_photo_2.png)

**Hotplate**
![Hotplate photo front](/Images/Hotplate_photo_1.png)
![Hotplate photo front](/Images/Hotplate_photo_2.png)

**Vapour phase (Fail)**
![Vapour phase photo 1](/Images/Vapour_phase_photo_1.png)
![Vapour phase photo 2](/Images/Vapour_phase_photo_2.png)

**Controller board**
![Controller board with display](/Images/Controller_board_V01_Angled_View_3D_Render.png)
![Controller board](/Images/Controller_board_V01_Angled_View_3D_Render_Without_Display.png)
![Controller board annotated](/Images/Controller_board_V01_Angled_View_3D_Render_annotated.png)

**AC power board**
![Power board](/Images/Power_board_V01_Angled_View_3D_Render.png)
![Power board annotated](/Images/Power_board_V01_Angled_View_3D_Render_Annotated.png)

**Command line interface**
![Terminal example 1](/Images/Terminal_CLI_example1.png)

### Features
* USB serial control
* USB programming (STM32 bootloader)
* USB Nextion programming
* SWD debug & programming
* Touch screen display
* 3 indipendant AC power control channels
  * Phase angle control
  * On-Off conrol
* Mains frequency measurement
* 5 RTD temperature sensor channels
* Buzzer
* safety/Isolation relay
* Over current protection (Fuse)

### Intro
I wanted to have a reflow oven so I could easilly solder electronic prototypes. After looking around I found plenty of DIY projects but none of them fitted my needs. I didn't want a arduino atmege128 as host MCU ,which most projects use and in addition I wanted complete control over the AC load, so no off the shelf solid state relay with buildin zerocross driver. I also like designing electronics :D. This is why I designed my own solution. I hope you like it, for me it has been quite a journey. From failed and forgotton projects to two functional devices and an AC controller and power board that can be used for all kinds of other projects.

### Warning!
Do not touch mains, I would love to read about your projects in the future.

This project uses mains voltages, so it could de dangerous.
It is mains earth referenced. meaning the digital ground is connected to earth, and earth is connected to the neutral wire of the mains supply. Avoid releasing the magic smoke from your Oscilloscope.
Watch [this](https://youtu.be/xaELqAo4kkQ) excellent video if you would like to learn more.

### Type of automated soldering machine to build?
After looking around the internet there are multiple automated soldering techniques / machines.
- vapour phase
- Infrared reflow oven
- Convection reflow oven
- Hotplate

After reading all the marketing material from several vapour phase manufacturers I settled for vapour phase as method of choice. Main reasoning at the time: _just heat up the Galden (special fluid) in a closed container with your pcb in it, no fears of overheating or difficult reflow profiles to implement._
However I later changed my mind, after a failed DIY vapour phase oven attempt, and decided to build a Infrared reflow oven instead. In addition I also build a PCB preheater/reflow hotplate because I had a failed preheater project laying around, that I was using for testing while awaiting components to arrive. Dicided to finish the hotplate project rip out its arduino brains and replace it with the newly created pcb's.

### What happened to the DIY Vapour Phase, why did it fail?
The first thing I did after deciding to build a vapour phase oven was buying a brand new cheap sousvide. Next I took it apart.
>Australian accent: "Don't turn it on take it appart."

Anticipating full ripening of the dissassembled components I left it under my workbench for a few weeks while designing the PCB's.

Next when the PCB's arrived (90% assembled by JLCPCB) I soldered the missing components and started with the firmware development Blinky, Hello world, Drivers.

The next step was testing, and here I made the discovered that I should have started off the project with a basic calculation before buying the sous vide.
I tested the heat up rate of 1 liter of water in the modified sous vide and discovered that heating up the water took way longer than expected. I started to worry that it might never reach the required temperature needed for soldering within a acceptable timeframe. So I did what I should have done beforehand and calculated the power requirements needed to heat up the Galden wihin a specified time ([How to Calculate Time to Heat Water](https://sciencing.com/calculate-time-heat-water-8028611.html)).
Even when ignoring thermal losses the modified sous vide was underpowered and additional heating elements and insulation were required to make it work...
At this point I looked up the price for the Vapour Phase fluid I would have needed ([Galden LS 230 500mL](https://www.eleshop.nl/vapour-phase-galden-ls-230-vloeistof-500ml.html)). Checked if I read the price correctly and promptly changed my mind and dicided to buy a Infrared reflow oven in the instead.
### Which IR-reflow oven to buy?
After doing some research I found several commercial reflow ovens but only one of them fitted the price range I had in mind. However after doing some more research I discoved both of the  the commercial options I found are flawed in multiple ways.

* T962/T962A IR Reflow oven

T962 is a know oven used by lots of hobbyists but the build quality is not great and the design is flawed. 
With modifications this can be good oven but this will result in a lot of work, A great video series about this oven and the needed modifications to make it work propperly can be found [here](https://www.youtube.com/watch?v=qVKl5L92t_A&list=PLzvLbUxGuZ-zK_24L4maC1OOX__b6bArA).

I also had a closer look at the available Vapour phase reflow ovens even though none of them actually fitted my price range, even when ignoring the very expensive vapour phase fluid (Galden). The best fit would be:
* Imdes Vapour phase soldering oven Mini Condens IT ([Eleshop](https://www.eleshop.nl/vapour-phase-soldeeroven-mini-condens-it.html))

I discovered after reading a forum post on the [EEVBLOG forum](https://www.eevblog.com/forum/reviews/finally!!-vapor-phase-reflow-oven-in-reach-of-the-diy-hobbyist!!!/) that the design and build quality of this device are sub optimal. It's just not worth the price they ask for it. So I went bak to designing my own solution.
### Purchase YARO?
It's 100% opensource so you can build it yourself and even improve and modify the design, I highly recommend doing so. However if you would like to purchase preassembled PCB's, I have some laying around I I'm willing to sell. If their is a enough interest I will consider doing a small production run and make these available for purchase as well. Let my know by sending me an email tomklijn@outlook.com.
### Support
If you would like to support me you can do so by buying me a coffee -> [Click Here](http://buymeacoffee.com/tomklijn) 

If you need support regarding this project just leave a comment on this github page I'll try to answer it as soon as possible.
