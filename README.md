🌍 Overview

MEGANOPOLY is a room-scale XR/VR reinterpretation of the classic Monopoly board game. Instead of controlling a token from above, players become life-sized avatars and physically exist inside a giant, living board.

Every tile glows, every event triggers a cinematic animation, and every negotiation happens face-to-face in immersive space. The board is set inside a Tunisian cultural environment — transforming a universal game into a deeply local experience, with 8 original mini-games inspired by Tunisian traditions and childhood games.

Core blend:

♟️ Strategic board gameplay
🤝 Social multiplayer with spatial voice chat
🎮 Immersive XR physical presence
🇹🇳 Tunisian cultural identity
🎮 Gameplay Loop
Roll Dice → Move Tiles → Land on Property
         ↓
   Buy it directly   OR   Challenge mini-game
         ↓                        ↓
  Pay standard cost        Win → property free
                           Lose → pay double, winner gets it free
         ↓
   Build houses → Collect rent → Bankrupt opponents → Win
🏗️ Scale & Environment
Element	Detail
Player scale	Life-sized 1:1 human avatars
Board scale	Room-scale VR / massive virtual plaza
Environment style	Tunisian-themed locals and architecture
Active players	4 simultaneous players per session
Tiles	Glow dynamically when active
✨ Core Features
🎲 Dice & Movement
Floating 3D holographic dice
Roll via hand gesture, grab-and-throw, or button (accessibility)
Glowing directional paths guide movement across the board
Physical locomotion — walking or XR teleport
🏠 Property System
Landing triggers holographic property UI with name and cost
Two options: buy directly or challenge opponents to a mini-game
Ownership shown via color glow and persistent visual markers
Houses drop from the sky with physics impact
🃏 Card System
Cards appear as floating holograms — grab or tap to reveal
Each card triggers a short cinematic:
💰 Money raining down
👮 Police escorting to jail
🚗 Mini pawn driving across the board
🌍 Environmental transformation effects
🤝 Trading & Negotiation
Two players stand face-to-face in XR space
Property cards and money stacks float between them
Real-time offer updates
Confirm via gesture, button, or physical signature motion
💬 Multiplayer
4 players in the same XR session
Spatial voice chat for natural communication
Holographic HUD per player: balance, properties, buildings, jail status
🗺️ Special Tiles
Tile	Experience
🎉 GO	Fireworks, money burst, celebration atmosphere
🚔 Jail	Holographic police escort, 3D animated cell
🌴 Free Parking	Chill zone, confetti, relaxed music
🚂 Railroads	Moving holographic trains on live tracks
🍀 Chance	Card with mostly positive effects
💀 Trap Space	Card with mostly negative effects
🎁 Item Space	Strategic item (e.g. custom dice — pick exact number)
🔀 Swap Space	Random chaotic outcome (e.g. forced money transfer)
🎯 Mini-Games — 8 Tunisian Cultural Games

Each property color is linked to a unique mini-game inspired by Tunisian traditions. Landing on a property gives you the option to challenge — win and get it free, lose and pay double.

Color	Mini-Game	Description
🟤 Brown	BISS	Precision marble game — throw into a hole in the fewest attempts
🔵 Light Blue	Khobz	Pull bread from a Tunisian oven at the exact right moment — no timer
🩷 Pink	Rock Paper Scissors	Gesture-based elimination — last one standing wins
🟠 Orange	Bent Walad	Speed word game — name animals, countries, jobs starting with a random letter
🔴 Red	Pottery Balance	Stack Nabeul pottery in the only valid configuration — physics-based
🟡 Yellow	Ghomidha (Hide and Seek)	Psychological elimination — hide from the seeker, survive the longest
🟢 Green	3allouch El Eid	Find your marked sheep in a crowded Eid market while opponents sabotage you
🔷 Dark Blue	Fass3a	Ring a neighbor's bell for points, escape before you're caught — risk vs reward
Difficulty System

Every mini-game has 3 difficulty levels that scale automatically with game progression:

Level 1 (Easy)   → Large margins, clear cues, forgiving physics
Level 2 (Medium) → Reduced margins, added complexity
Level 3 (Hard)   → Tight precision, distractions, no assistance
🛠️ Tech Stack
Technology	Usage
Unity 6 (C#)	Core engine, gameplay systems, game logic
Meta Quest SDK	VR input, hand tracking, headset integration
Unity XR Toolkit	XR interaction framework, locomotion
Unity Netcode	Multiplayer networking, 4-player sync
NavMesh / Unity AI	NPC behavior (police, market crowds)
Spatial Audio	Voice chat, positional sound effects
Unity Physics	Dice throw, pottery stacking, marble rolling
📁 Project Structure
Assets/
├── Scripts/
│   ├── Core/              # Turn system, game flow, win conditions
│   ├── Board/             # Tile logic, property ownership, rent
│   ├── Dice/              # Roll mechanics, animation, result handling
│   ├── MiniGames/
│   │   ├── BISS/
│   │   ├── Khobz/
│   │   ├── RockPaperScissors/
│   │   ├── BentWalad/
│   │   ├── PotteryBalance/
│   │   ├── Ghomidha/
│   │   ├── AllounchElEid/
│   │   └── Fass3a/
│   ├── Multiplayer/       # Netcode, player sync, voice chat
│   ├── UI/                # Holographic HUD, trading interface
│   ├── Cards/             # Chance, trap, item, swap logic
│   └── Trading/           # Negotiation system, offer management
├── Prefabs/
│   ├── Board/             # Tiles, properties, special spaces
│   ├── Players/           # Avatars, holographic pawns
│   ├── MiniGames/         # Per-game prefabs and environments
│   └── VFX/               # Fireworks, money rain, cinematic effects
├── Scenes/
│   ├── MainBoard
│   ├── MiniGame_Hub
│   └── [8 MiniGame Scenes]
└── XR/                    # Meta Quest XR configuration
🚀 Getting Started
Prerequisites
Unity 6.x
Meta Quest Developer Hub
Meta XR SDK
Unity Netcode for GameObjects
Run Locally
bash
# Clone the repository
git clone https://github.com/Salmiselim/meganopoly.git

# Open in Unity 6.x
# Build target: Android (Meta Quest)
# Enable XR Plugin: Oculus

# For multiplayer testing:
# Build and deploy to 2–4 Quest headsets on the same network
# Or use Unity Relay for remote testing
🎯 Development Status
Module	Status
Board layout & XR environment	✅ Complete
Turn system & game logic	✅ Complete
Dice interaction	✅ Complete
Property ownership & rent	✅ Complete
Holographic HUD	✅ Complete
4-player multiplayer	✅ Complete
Trading & negotiation	✅ Complete
Special tiles (GO, Jail, etc.)	✅ Complete
Mini-game framework	✅ Complete
All 8 mini-games	✅ Complete
Difficulty scaling	✅ Complete
Polish & VFX	🟡 In Progress
👨‍💻 Author

Selim Salmi

🌐 selim-salmi.tn
💼 linkedin.com/in/selim-salmi
🐱 github.com/Salmiselim

Built as a Master's-level graduation project at ESPRIT Tunisia — combining XR development, multiplayer networking, game design, and Tunisian cultural heritage into one immersive experience.
