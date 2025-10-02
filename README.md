# text-war-sim
A C based wargame simulation project built quickly then refactored to try and better capture initial goals of a modular arhitecture inspired by MOSA.
The goal for the engine itself is to capture conditionals such as type, weather, terrain, support systems and combat situationals and convert those into -> modifiers to allow for a calculation of victory/defeat in scenarios looking at the probability based off certain requirements.

Future plans: 
Strategic Map System:
Use a 10 x 10 grid map to display units, terrain modifiers and have a fog of war system to effect it. 

Within this:

Terrain Types [ Urban, Open Field, Mountains, Desert, Snow, Swamp, Beach ]
Unit Presence [ Infantry, Vehicles, Air assets ] - including drones for aerial surveliance to even odds and get ambush modifers for example.
Visibility fog of war limits and unit visibility range

Combat will be resolved based on encounters with a unit based encounter system with modifiers coming from all of above.
A roll system will be put in place : Still strongly favoring stronger/larger units but, allowing for chances of great turn of events in some scenarios simulating some battlefield chaos.




UML/Flow:
<img width="1505" height="1041" alt="text-war-simUML drawio" src="https://github.com/user-attachments/assets/c9272940-d1ab-4984-a48c-ca01b4586150" />
