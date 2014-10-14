#include "Gameboard.h"

//ADD DESTRUCTORS!

/*
	Constructor for the Gameboard.
	Creates a 2D array of Room pointers.
	Adds Items or NPCs to appropriate Rooms.
	*/
Gameboard::Gameboard()
{
	Room* room0000 = new Room("Room [00][00]", "You are on the water.", "The waves to the North and West look impassable. There is an island to the South-East.",
		false, true, true, false, 0, 0, true);
	Room* room0001 = new Room("Room [00][01]", "You are on the water.", "The waves to the West look impassable. There is an island to the South-East.",
		true, true, true, false, 0, 1, true); 
	Room* room0002 = new Room("Room [00][02]", "You are on the water.", "The waves to the West look impassable. There is an island to the East.",
		true, true, true, false, 0, 2, true); 
	Room* room0003 = new Room("Room [00][03]", "You are on the water.", "The waves to the West look impassable. There is an island to the East.",
		true, true, true, false, 0, 3, true); 
	Room* room0004 = new Room("Room [00][04]", "You are on the water.", "The waves to the West look impassable. There is an island to the East.",
		true, true, true, false, 0, 4, true); 
	Room* room0005 = new Room("Room [00][05]", "You are on the water.", "The waves to the West look impassable. There is an island to the North-East.",
		true, true, true, false, 0, 5, true); 
	Room* room0006 = new Room("Room [00][06]", "You are on the water.", "The waves to the West look impassable. There is an island to the North-East and another island to the South-East.",
		true, true, true, false, 0, 6, true); 
	Room* room0007 = new Room("Room [00][07]", "You are on the water.", "The waves to the West look impassable. There is a small island to the South-East.",
		true, true, true, false, 0, 7, true); 
	Room* room0008 = new Room("Room [00][08]", "You are on the water.", "The waves to the West look impassable. There is a small island to the East.",
		true, true, true, false, 0, 8, true); 
	Room* room0009 = new Room("Room [00][09]", "You are on the water.", "The waves to the West and South look impassable. There is a small island to the North-East.",
		true, true, false, false, 0, 9, true); 
	Room* room0100 = new Room("Room [01][00]", "You are on the water.", "The waves to the North look impassable. There is an island to the South.",
		false, true, true, true, 1, 0, true); 
	Room* room0101 = new Room("Room [01][01]", "You are on the water.", "There is a fairly large island to the South.",
		true, true, true, true, 1, 1, true); 
	Room* room0102 = new Room("Room [01][02]", "You are on a beach in the North-West corner of the island.", "There seems to be some large metallic structure to the South-East.",
		true, true, true, true, 1, 2, false); 
	Room* room0103 = new Room("Room [01][03]", "You are in the middle of a beach on the West side of the island.", "There is a large metallic structure to the East that is not accessible from this side.",
		true, false, true, true, 1, 3, false); 
	Room* room0104 = new Room("Room [01][04]", "You are on a beach in the South-West corner of the island.", "There is a large metallic structure to the North-East.",
		true, true, true, true, 1, 4, false); 
	Room* room0105 = new Room("Room [01][05]", "You are on the water.", "There is a decent sized island to the North.",
		true, true, true, true, 1, 5, true); 
	Room* room0106 = new Room("Room [01][06]", "You are on the water.", "There is a decent sized island to the North and a small island to the South.",
		true, true, true, true, 1, 6, true); 
	Room* room0107 = new Room("Room [01][07]", "You are on the water.", "There is a small island to the South.",
		true, true, true, true, 1, 7, true); 
	
	Room* room0108 = new Room("Room [01][08]", "You are on a very small island.", "There seems to be some sort of chest sticking halfway out of the sand. It looks very old.",
		true, true, true, true, 1, 8, false); 
	room0108->addItem(new Chest("chest", "A shiny chest. I wonder what is inside.", false));

	Room* room0109 = new Room("Room [01][09]", "You are on the water.", "The waves to the South look impassable. There is a small island to the North.",
		true, true, false, true, 1, 9, true); 
	Room* room0200 = new Room("Room [02][00]", "You are on the water.", "The waves to the North look impassble. There is an island to the South.",
		false, true, true, true, 2, 0, true); 
	Room* room0201 = new Room("Room [02][01]", "You are on the water.", "There is a large island to the South.",
		true, true, true, true, 2, 1, true); 
	Room* room0202 = new Room("Room [02][02]", "You are in the middle of a beach on the North side of the island.", "There is a large structure to the South but it is not accessible from this side",
		true, true, false, true, 2, 2, false); 
	
	Room* room0203 = new Room("Room [02][03]", "You are in a very advanced looking vehicle of somekind.", "This looks more like a space vehicle. There is a display screen that says \"Captain’s log\". The main flight console is to the East.",
		false, true, true, false, 2, 3, false);
	room0203->addItem(new Paper("ai log","Captain: Drilner\nDate: 3rd day of the 7th Lunar Eclipse\nTime: 4213\nSystem malfunction...\nDrive overheating...\nPreparing for crash landing...", false));
	room0203->addItem(new Paper("portrait", "It's a portrait of yourself. It says \"Captain Drilner\"", false));
	room0203->setLighting(false);

	Room* room0204 = new Room("Room [02][04]", "You are in the middle of a beach on the South side of the island.", "There is a very large metallic structure to the North which appears to have an entrance.",
		true, true, true, true, 2, 4, false); 
	Room* room0205 = new Room("Room [02][05]", "You are on the water.", "There is a large island to the North.",
		true, true, true, true, 2, 5, true); 
	Room* room0206 = new Room("Room [02][06]", "You are on the water.", "There is a large island to the North and a small island to the South-West.",
		true, true, true, true, 2, 6, true); 
	Room* room0207 = new Room("Room [02][07]", "You are on the water.", "There is a small island to the South-West.",
		true, true, true, true, 2, 7, true); 
	Room* room0208 = new Room("Room [02][08]", "You are on the water.", "There is a small island to the West.",
		true, true, true, true, 2, 8, true); 
	Room* room0209 = new Room("Room [02][09]", "You are on the water.", "The waves look impassable to the South. There is a small island to the North-West.",
		true, true, false, true, 2, 9, true); 
	Room* room0300 = new Room("Room [03][00]", "You are on the water.", "The waves look impassable to the North. There is an island to the South.",
		false, true, true, true, 3, 0, true); 
	Room* room0301 = new Room("Room [03][01]", "You are on the water.", "There is a large island to the South.",
		true, true, true, true, 3, 1, true); 
	Room* room0302 = new Room("Room [03][02]", "You are on a beach on the North-East corner of the island.", "There seems to be a very large metallic structure to the South but it is not accessible from this side.",
		true, true, false, true, 3, 2, false); 
	
	Room* room0303 = new Room("Room [03][03]", "You are in the flight control room of the ship.", "In the center of the highly complex control panel, you see a large cylindrical object that looks vital to the control panel.",
		false, false, false, true, 3, 3, false); 
	room0303->setLighting(false);
	room0303->addItem(new HyperDrive("hyper drive", "For some reason you know exactly what this is. It's the hyper drive for a KT-77 explorer craft made by Kiln-Teq Inc. Issued to all First-Class Scouts of the Terhath Space Alliance.\nIt is sticking out, maybe it should be pushed back in.", false));

	Room* room0304 = new Room("Room [03][04]", "You are on a beach on the South-East corner of the island.", "There seems to be a very large metallic structure to the North but it is not accessible from this side.",
		false, true, true, true, 3, 4, false); 
	Room* room0305 = new Room("Room [03][05]", "You are on the water.", "There is a large island to the North and a large island in the distance to the East.",
		true, true, true, true, 3, 5, true); 
	Room* room0306 = new Room("Room [03][06]", "You are on the water.", "There is a large island to the North and a large island in the distance to the East.",
		true, true, true, true, 3, 6, true); 
	Room* room0307 = new Room("Room [03][07]", "You are on the water.", "There is a large island in the distance to the North, a large island in the distance to the East, and a small island to the South-West.",
		true, true, true, true, 3, 7, true); 
	Room* room0308 = new Room("Room [03][08]", "You are on the water.", "There is a large island in the distance to the East, and a small island to the West.",
		true, true, true, true, 3, 8, true); 
	Room* room0309 = new Room("Room [03][09]", "You are on the water.", "The waves to the South look impassable. There is a large island in the distance to the North-East, and a small island to the North-West.",
		true, true, false, true, 3, 9, true); 
	Room* room0400 = new Room("Room [04][00]", "You are on the water.", "The waves to the North look impassable. There is a large island to the South-West.",
		false, true, true, true, 4, 0, true); 
	Room* room0401 = new Room("Room [04][01]", "You are on the water.", "There is a large island to the South-West.",
		true, true, true, true, 4, 1, true); 
	Room* room0402 = new Room("Room [04][02]", "You are on the water.", "There is a large island to the West and an island in the distance to the East.",
		true, true, true, true, 4, 2, true); 
	Room* room0403 = new Room("Room [04][03]", "You are on the water.", "There is a large island to the West but it looks impassable that way because some large metallic object is blocking your path.",
		true, true, true, false, 4, 3, true); 
	Room* room0404 = new Room("Room [04][04]", "You are on the water.", "There is a large island to the West and a large island to the South-East.",
		true, true, true, true, 4, 4, true); 
	Room* room0405 = new Room("Room [04][05]", "You are on the water.", "There is a large island to the North-West and a large island to the East.",
		true, true, true, true, 4, 5, true); 
	Room* room0406 = new Room("Room [04][06]", "You are on the water.", "There is a large island to the North-West and a large island to the East.",
		true, true, true, true, 4, 6, true); 
	Room* room0407 = new Room("Room [04][07]", "You are on the water.", "There is a large island to the East and a small island in the distance to the West.",
		true, true, true, true, 4, 7, true); 
	Room* room0408 = new Room("Room [04][08]", "You are on the water.", "There is a large island to the East and a small island in the distance to the West.",
		true, true, true, true, 4, 8, true); 
	Room* room0409 = new Room("Room [04][09]", "You are on the water.", "The waves to the South look impassable. There is a large island to the North-East and a small island in the distance to the West.",
		true, true, false, true, 4, 9, true); 
	Room* room0500 = new Room("Room [05][00]", "You are on the water.", "The waves to the North look impassable. There are islands to the South-East and South-West.",
		false, true, true, true, 5, 0, true);
	Room* room0501 = new Room("Room [05][01]", "You are on the water.", "There are islands to the East and South-West.",
		true, true, true, true, 5, 1, true);
	Room* room0502 = new Room("Room [05][02]", "You are on the water.", "There are islands to the East and West.",
		true, true, true, true, 5, 2, true);
	Room* room0503 = new Room("Room [05][03]", "You are on the water.", "There are islands to the North-East, South-East, and West.",
		true, true, true, true, 5, 3, true);
	Room* room0504 = new Room("Room [05][04]", "You are on the water.", "There are islands to the North-East, South-East, and West.",
		true, true, true, true, 5, 4, true);
	Room* room0505 = new Room("Room [05][05]", "You are on the water.", "There are islands to the East and North-West.",
		true, true, true, true, 5, 5, true);
	Room* room0506 = new Room("Room [05][06]", "You are on the water.", "There are islands to the East and North-West.",
		true, true, true, true, 5, 6, true);
	Room* room0507 = new Room("Room [05][07]", "You are on the water.", "There is an island to the East.",
		true, true, true, true, 5, 7, true);
	Room* room0508 = new Room("Room [05][08]", "You are on the water.", "There is an island to the East.",
		true, true, true, true, 5, 8, true);
	Room* room0509 = new Room("Room [05][09]", "You are on the water.", "The waves to the South look impassable. There is an island to the North-East.",
		true, true, false, true, 5, 9, true);
	Room* room0600 = new Room("Room [06][00]", "You are on the water.", "The waves to the North look impassable. There is an island to the South-East.",
		false, true, true, true, 6, 0, true);
	Room* room0601 = new Room("Room [06][01]", "You are on the water.", "There is an island to the East.",
		true, true, true, true, 6, 1, true);
	Room* room0602 = new Room("Room [06][02]", "You are on the water.", "There is an island to the East.",
		true, true, true, true, 6, 2, true);
	Room* room0603 = new Room("Room [06][03]", "You are on the water.", "There are islands to the North-East and South.",
		true, true, true, true, 6, 3, true);
	Room* room0604 = new Room("Room [06][04]", "You are on the water.", "There is an island to the North-East and one directly South.",
		true, true, true, true, 6, 4, true);

	Room* room0605 = new Room("Room [06][05]", "You are on the North-West shore of what looks to be an island.", "There are some trees here.",
		false, true, true, false, 6, 5, false);
	room0605->addItem(new Tree("tree", "A tree that could be usefull if chopped down.", false));

	Room* room0606 = new Room("Room [06][06]", "You are on the beach of the West side of the island.", "There is a red crab by your feet. Better keep moving before he takes a toe.",
		true, true, true, false, 6, 6, false);
	Room* room0607 = new Room("Room [06][07]", "You are on the West side of the island.", "The sound of the waves splashing against the rocky shore is pleasing.",
		true, true, true, false, 6, 7, false);
	Room* room0608 = new Room("Room [06][08]", "You are on a rocky South-West corner of the island.", "These rocks look sharp; better be careful.",
		true, true, false, false, 6, 8, false);
	Room* room0609 = new Room("Room [06][09]", "You are on the water.", "The waves to the South look impassable. There is an island to the North.",
		true, true, false, true, 6, 9, true);
	Room* room0700 = new Room("Room [07][00]", "You are on the water.", "The waves to the North look impassable. There is an island to the South.",
		false, true, true, true, 7, 0, true);

	Room* room0701 = new Room("Room [07][01]", "You are on the North side of the island", "To the East is the left side of a small hut.",
		false, false, true, false, 7, 1, false);

	Room* room0702 = new Room("Room [07][02]", "You are on the South-West side of a small island.", "There looks to be a building to the North-East.",
		true, true, false, false, 7, 2, false);
	room0702->addItem(new Tree("tree", "A nice looking tree, maybe it can be chopped down.", false));

	Room* room0703 = new Room("Room [07][03]", "You are on the water.", "There is an island to the North and to the South.",
		true, true, true, true, 7, 3, true);
	Room* room0704 = new Room("Room [07][04]", "You are on the water.", "There is an island to the North and the South.",
		true, true, true, true, 7, 4, true);
	Room* room0705 = new Room("Room [07][05]", "You are on the North shore of the island.", "The sound of waves sooths your soul. Is that a building to the South-East?",
		false, true, true, true, 7, 5, false);
	Room* room0706 = new Room("Room [07][06]", "You are to the left of a shack.", "The shack to the East looks make-shift and appears to be falling apart.",
		true, false, true, true, 7, 6, false);

	Room* room0707 = new Room("Room [07][07]", "You are in a small patch of trees.", "You hear the birds chirp and the small animals scurry. It's sort of nice.",
		true, true, true, true, 7, 7, false);
	room0707->addItem(new Tree("tree", "A tree that could be usefull if chopped down.", false));

	Room* room0708 = new Room("Room [07][08]", "You are on the sandy beach.", "The waves flow over your feet. To the East looks to be some trees.",
		true, true, false, true, 7, 8, false);
	Room* room0709 = new Room("Room [07][09]", "You are on the water.", "The waves to the South look impassable. To the North is a large island.",
		true, true, false, true, 7, 9, true);
	Room* room0800 = new Room("Room [08][00]", "You are on the water.", "The waves to the North look impassable. There is an island to the South.",
		false, true, false, true, 8, 0, true);

	Room* room0801 = new Room("Room [08][01]", "You are in the shop.", "Why is there a shop here? It makes just about zero sense. The shop looks old and rustic.",
		false, false, true, false, 8, 1, false);
	Shopkeeper* shopKeeper = new Shopkeeper("Shopkeeper", "A gangly looking old man. It looks like he has some things to sell.", 1, 0, false);
	shopKeeper->addToInventory(new Container("container", "A plastic container. You guess it's about two quarts in size.", false));
	shopKeeper->addToInventory(new Match("match", "A strike-anywhere match. Woah! Strike anywhere? Be careful with that!", true));
	shopKeeper->addToInventory(new Match("match", "A strike-anywhere match. Woah! Strike anywhere? Be careful with that!", true));
	shopKeeper->addToInventory(new Match("match", "A strike-anywhere match. Woah! Strike anywhere? Be careful with that!", true));
	shopKeeper->addToInventory(new Match("match", "A strike-anywhere match. Woah! Strike anywhere? Be careful with that!", true));
	shopKeeper->addToInventory(new Match("match", "A strike-anywhere match. Woah! Strike anywhere? Be careful with that!", true));
	shopKeeper->addToInventory(new Torch("torch", "A wooden torch that can be lit with a match.", false));
	room0801->addNonPlayableCharacter(shopKeeper);

	Room* room0802 = new Room("Room [08][02]", "You are on the South-East shore of this small island.", "Man those wave sound nice! This weird shop is to the North.",
		true, false, false, true, 8, 2, false);
	Room* room0803 = new Room("Room [08][03]", "You are on the water.", "There is an island to the North and a bigger one to the South.",
		true, true, true, true, 8, 3, true);
	Room* room0804 = new Room("Room [08][04]", "On the water, you are.", "There is an island to the North and one very close to your South.",
		true, true, true, true, 8, 4, true);
	Room* room0805 = new Room("Room [08][05]", "You are on the Northern shore.", "Wow, this is a nice shore; it's very shorey. You're on the North side of an old shack.",
		false, true, false, true, 8, 5, false);

	Room* room0806 = new Room("Room [08][06]", "You are in the shack.", "You are in the old shack. It appears that someone has died here. It would be such a shame to take anything...",
		false, false, true, false, 8, 6, false);
	room0806->addItem(new Rope("rope", "This rope looks strong! Maybe it can be used with something? Hmm...", true));
	room0806->addItem(new MoneyPouch("old money pouch", "This money pouch is so old it is cracking. Better rescue the good stuff inside (the money).", true, 15));
	room0806->addItem(new Paper("instructions", "How to Build a Raft\n--------------------\nUse rope on logs\n", true));

	Room* room0807 = new Room("Room [08][07]", "You are in a prairie.", "The grass tickles your knees. Wait, are those even knees? The wide open field is a nice change. To the North is a shack and South are some trees.",
		true, true, true, true, 8, 7, false);
	Room* room0808 = new Room("Room [08][08]", "You are in a patch of rotted trees on the South shore.", "These trees don't look like they could be used at all, darn.",
		true, true, false, true, 8, 8, false);
	Room* room0809 = new Room("Room [08][09]", "You are on the water.", "The waves to the South look impassable. There is an island to the North.",
		true, true, false, true, 8, 9, true);
	Room* room0900 = new Room("Room [09][00]", "You are on the water.", "The waves to the North look impassable. There is an island to the South-West.",
		false, true, true, true, 9, 0, true);
	Room* room0901 = new Room("Room [09][01]", "You are on the water.", "There is an island to the West.",
		true, true, true, false, 9, 1, true);
	Room* room0902 = new Room("Room [09][02]", "You are on the water.", "There is an island to the West.",
		true, true, true, true, 9, 2, true);
	Room* room0903 = new Room("Room [09][03]", "You are on the water.", "There is an island to the North-West and one to the South.",
		true, true, true, true, 9, 3, true);
	Room* room0904 = new Room("Room [09][04]", "You are on the water.", "That island to the South sure does look big. I wonder what's on it.",
		true, true, true, true, 9, 4, true);
	Room* room0905 = new Room("Room [09][05]", "You are standing next to an inlet on the North-East corner of the island.", "You see different fish swimming in the inlet. It must be nice to be a fish.",
		false, false, true, true, 9, 5, false);
	Room* room0906 = new Room("Room [09][06]", "You are on the East beach of the island.", "To the left is a weird shack or hutt. Looks like the door is on another side.",
		true, false, true, false, 9, 6, false);
	Room* room0907 = new Room("Room [09][07]", "You are on the shore.", "A few crabs start scurrying towards you. They don't look friendly.",
		true, false, true, true, 9, 7, false);

	Room* room0908 = new Room("Room [09][08]", "You are on the South-East side of a large island.", "To the South-East is the big blue ocean. The sand on the shore is a nice light brown. It's warm.",
		true, false, false, true, 9, 8, false);
	room0908->addItem(new Hatchet("hatchet", "A rusty old hatchet; may still have some use left in it.", true));

	Room* room0909 = new Room("Room [09][09]", "You are on the water.", "The waves to the South look impassable. There is a large island to the North.",
		true, true, false, true, 9, 9, true);
	Room* room1000 = new Room("Room [10][00]", "You are on the water.", "The waves to the North and East look impassable. There is an island to the South-West.",
		false, false, true, true, 10, 0, true);
	Room* room1001 = new Room("Room [10][01]", "You are on the water.", "The waves to the East look impassable. There is an island to the West.",
		true, false, true, true, 10, 1, true);
	Room* room1002 = new Room("Room [10][02]", "You are on the water.", "The waves to the East look impassable. There appears to be an island to the West.",
		true, false, true, true, 10, 2, true);
	Room* room1003 = new Room("Room [10][03]", "You are on the water.", "The waves to the East look impassable. There is an island to the North-West.",
		true, false, true, true, 10, 3, true);
	Room* room1004 = new Room("Room [10][04]", "You are on the water.", "The waves to the East look impassable.There is an island to the South-West.",
		true, false, true, true, 10, 4, true);
	Room* room1005 = new Room("Room [10][05]", "You are on the water.", "The waves to the East look impassable. There is an island directly to the West.",
		true, false, true, true, 10, 5, true);
	Room* room1006 = new Room("Room [10][06]", "You are on the water.", "The waves to the East look impassable. There is an island to the West.",
		true, false, true, true, 10, 6, true);
	Room* room1007 = new Room("Room [10][07]", "You are on the water.", "The waves to the East look impassable. There is an island to the West.",
		true, false, true, true, 10, 7, true);
	Room* room1008 = new Room("Room [10][08]", "You are on the water.", "The waves to the East look impassable. There is an island to the West.",
		true, false, true, true, 10, 8, true);
	Room* room1009 = new Room("Room [10][09]", "You are on the water.", "The waves to the East and South look impassable. There is an island to the North-West.",
		true, false, false, true, 10, 9, true);
	
	// adding rooms to the 2D array
	array[0][0] = room0000;
	array[1][0] = room0100;
	array[2][0] = room0200;
	array[3][0] = room0300;
	array[4][0] = room0400;
	array[5][0] = room0500;
	array[6][0] = room0600;
	array[7][0] = room0700;
	array[8][0] = room0800;
	array[9][0] = room0900;
	array[10][0] = room1000;

	array[0][1] = room0001;
	array[1][1] = room0101;
	array[2][1] = room0201;
	array[3][1] = room0301;
	array[4][1] = room0401;
	array[5][1] = room0501;
	array[6][1] = room0601;
	array[7][1] = room0701;
	array[8][1] = room0801;
	array[9][1] = room0901;
	array[10][1] = room1001;

	array[0][2] = room0002;
	array[1][2] = room0102;
	array[2][2] = room0202;
	array[3][2] = room0302;
	array[4][2] = room0402;
	array[5][2] = room0502;
	array[6][2] = room0602;
	array[7][2] = room0702;
	array[8][2] = room0802;
	array[9][2] = room0902;
	array[10][2] = room1002;

	array[0][3] = room0003;
	array[1][3] = room0103;
	array[2][3] = room0203;
	array[3][3] = room0303;
	array[4][3] = room0403;
	array[5][3] = room0503;
	array[6][3] = room0603;
	array[7][3] = room0703;
	array[8][3] = room0803;
	array[9][3] = room0903;
	array[10][3] = room1003;

	array[0][4] = room0004;
	array[1][4] = room0104;
	array[2][4] = room0204;
	array[3][4] = room0304;
	array[4][4] = room0404;
	array[5][4] = room0504;
	array[6][4] = room0604;
	array[7][4] = room0704;
	array[8][4] = room0804;
	array[9][4] = room0904;
	array[10][4] = room1004;

	array[0][5] = room0005;
	array[1][5] = room0105;
	array[2][5] = room0205;
	array[3][5] = room0305;
	array[4][5] = room0405;
	array[5][5] = room0505;
	array[6][5] = room0605;
	array[7][5] = room0705;
	array[8][5] = room0805;
	array[9][5] = room0905;
	array[10][5] = room1005;

	array[0][6] = room0006;
	array[1][6] = room0106;
	array[2][6] = room0206;
	array[3][6] = room0306;
	array[4][6] = room0406;
	array[5][6] = room0506;
	array[6][6] = room0606;
	array[7][6] = room0706;
	array[8][6] = room0806;
	array[9][6] = room0906;
	array[10][6] = room1006;

	array[0][7] = room0007;
	array[1][7] = room0107;
	array[2][7] = room0207;
	array[3][7] = room0307;
	array[4][7] = room0407;
	array[5][7] = room0507;
	array[6][7] = room0607;
	array[7][7] = room0707;
	array[8][7] = room0807;
	array[9][7] = room0907;
	array[10][7] = room1007;

	array[0][8] = room0008;
	array[1][8] = room0108;
	array[2][8] = room0208;
	array[3][8] = room0308;
	array[4][8] = room0408;
	array[5][8] = room0508;
	array[6][8] = room0608;
	array[7][8] = room0708;
	array[8][8] = room0808;
	array[9][8] = room0908;
	array[10][8] = room1008;

	array[0][9] = room0009;
	array[1][9] = room0109;
	array[2][9] = room0209;
	array[3][9] = room0309;
	array[4][9] = room0409;
	array[5][9] = room0509;
	array[6][9] = room0609;
	array[7][9] = room0709;
	array[8][9] = room0809;
	array[9][9] = room0909;
	array[10][9] = room1009;
}

/*
	Destructor for Gameboard.
	Deletes the room pointers in the 2D array.
*/
Gameboard::~Gameboard()
{
	for(int x = 0; x < COLUMNS; ++x)
	{
		for(int y = 0; y < ROWS; ++y)
		{
			if (array[x][y] != NULL)
			{
				delete array[x][y];
				array[x][y] = NULL;
			}
		}
	}
}

/*
	Returns the Room in the 2D array at [x][y].
	@param x the x value for room
	@param y the y value for room
	@return array[x][y] the room pointer based on incoming parameters
*/
Room* Gameboard::getRoom(int x, int y) const
{
	assert (array[x][y] != NULL);
	return array[x][y];
}

/*
	Returns the number of columns in gameboard.
	@return COLUMNS the const int for columns
*/
int Gameboard::getColumns() const
{
	return COLUMNS;
}

/*
	Returns the number of rows in gameboard.
	@return ROWS the const int for rows
*/
int Gameboard::getRows() const
{
	return ROWS;
}

