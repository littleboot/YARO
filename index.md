## YARO - Yet Another Reflow Oven
Yet Another Reflow Oven. An open source DIY Reflow Hotplate and Vapour phase controller including build instruction. 

### Result

### Project origin
I wanted to have a reflow oven so I could easilly solder electronic prototypes. After looking around I found plenty of DIY projects but none of them fitted my needs (also I like doing things my way). The big disadvantage of these projects is that they use an arduino in combination with a cheap solid state relay that is not suited for phase angle control.

#### What is the best soldering technique and device to build?
After looking around the internet there are multiple automated soldering techniques / machines.
- vapour phase
- Infrared reflow oven
- Convection reflow oven
- Hotplate

After reading all the marketing material from several vapour phase reflow oven manufacturers I settled for vapour phase as method of choice. Main reasoning at the time: _just heat up the "Vapour phase Galden" in a closed container with your pcb in it, no fears of overheating or difficult reflow profiles to implement._
However I later changed my mind, after a failed DIY vapour phase oven attempt, and decided to build a Infrared reflow oven instead. In addition I also build a PCB preheater/reflow hotplate because I had a failed preheater project laying around.

### Build first Think later
_What is the first thing you do when starting a project?_

> My answer at the time: Start buying stuf to take apart, leave it to rest, follow up by converting it to something that vaguely matches the project goal and finish off by discovering why it does not work.

### What happened to the DIY Vapour Phase?
After testing the heat up rate of 1 liter of water in the modified proficook (sous vide 500W).
I discovered heating up the water took way longer than expected. And started to worry it might never reach the required temperature needed for soldering. So I did what I should have done beforehand and calculated the power requirements needed to heat up the Galden wihin a specified time ([How to Calculate Time to Heat Water](https://sciencing.com/calculate-time-heat-water-8028611.html)).
So i discovered that even when ignoring thermal losses the modified proficook was underpowered and additional heating elements and insulation were required to make it work...
At this point I looked up the price for the Vapour Phase fluid I would have needed ([Galden LS 230 500mL](https://www.eleshop.nl/vapour-phase-galden-ls-230-vloeistof-500ml.html)). Checked if I read the price correctly and promptly changed my mind and dicided to build or buy a Infrared reflow oven in the instead.

### DIY or Buy?
After doing some research I found several commercial reflow ovens but only one of them fitted the price range I had in mind. However after doing some more research I discoved both of the  the commercial options I found are flawed in multiple ways.

* T962/T962A IR Reflow oven

T962 is a know oven used by lots of hobbyists but the build quality is not great and the design is flawed. 
With modifications this can be very good but this will result in a lot of work, A great video series about this oven and the needed modifications to make it work can be found [here](https://www.youtube.com/watch?v=qVKl5L92t_A&list=PLzvLbUxGuZ-zK_24L4maC1OOX__b6bArA).

I also had a closer look at the available Vapour phase reflow ovens even though none of them actually fitted my price range, even when ignoring the very expensive vapour fluid (Galden) I would have needed in addtion. The best fit would be:
* Imdes Vapour phase soldering oven Mini Condens IT ([Eleshop](https://www.eleshop.nl/vapour-phase-soldeeroven-mini-condens-it.html))

I discovered after reading a forum post on the [EEVBLOG forum](https://www.eevblog.com/forum/reviews/finally!!-vapor-phase-reflow-oven-in-reach-of-the-diy-hobbyist!!!/) that the design and build quality of this device are sub optimal. It's just not worth the price they ask for it.
So DIY it is.

### Purchase YARO?
It's 100% opensource so you can build it yourself and even improve and modify the design, I highly recommend doing so. However if you would like to purchase preassembled PCB's, I have some laying around I I'm willing to sell. If their is a enough interest I will consider doing a small production run and make these available for purchase as well. Let my know by sending me an email tomklijn@outlook.com.
### Support
If you would like to support me you could buy me a coffee -> [Click Here](http://buymeacoffee.com/tomklijn) 

If you need support regarding this project just leave a comment on this github page I'll try to answer it as soon as possible.
