Hackathon for a Better Driving Experience - Team Boba Fett
====
![HackathonBDE](https://pbs.twimg.com/profile_banners/704618465592741888/1456916176/1500x500)
This repository contains our submit for 2016 Hackathon for a Better Driving Experience, 
hosted by UPC and sponsored by SEAT and Altran. You may find more information in its [official
website](http://cit.upc.edu/hackathon/) and [Twitter Profile](https://twitter.com/hackathonbde)

Haptic Feedback Steering Wheel Prototype 
-------
Our project consists of a driving wheel with haptic feedback capabilities.

Feedback through the steering wheel is an innovative idea which generates a new concept in the Human-Machine-Interface.

You may not realize it, but almost all of your senses contribute to your driving. You don’t just see where you’re going 
and how fast you are relative to other vehicles and objects. You hear those vehicles, wind noise and the RPM of your engine.
You feel your own acceleration and braking. Your sense of balance helps you to know how sharply you are turning and whether
the road is banked. Likewise, your car communicates to you in the feel of the pedals and steering wheel.

About the last one, the steering wheel is able to transmit a feel for the road by twitching noticeably when a wheel encounters
road imperfections. Then, why not introduce a new sensation in the driving experience?

The concept tha rely is really simple: While driving, we are constantly holding and touching the 
steering wheel, so we wanted to use this fact to integrate a notification system using controlled
vibrations in the driving wheel, adding the touching sense to the driving experience.

Prototyping
-----------
Using a couple of unbalanced weighted motors inside a videogames controller and an Arduino as
control and simulation system, we built a functional prototype, giving feedback on several simulated driving events:

- Low fuel level
- Unfastened seat belt
- Speed limit reached
- Lane Departure Warning (LDW)

Each event has its own vibration pattern, distinct from the others, and in addition we give a short description 
message about the event using an LCD panel.

We simulated these events using electronic components (trimmers, switches and a gyroscope), but the point of
this project is to integrate this haptic feedback system with the whole car sensor network, notifying the
driver all the relevant events using vibrations.
