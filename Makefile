CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD
MAINOBJ = main.o
FLOOROBJ = chamber.o position.o grid.o door.o empty.o floor.o hwall.o passageway.o stair.o tile.o vwall.o gamesubject.o
CHAROBJ = character.o
PLAYEROBJ = playerCharacter.o shade.o goblin.o troll.o drow.o vampire.o
NPCOBJ = npc.o dragon.o dwarf.o elf.o halfling.o human.o merchant.o orc.o
ITEMOBJ = potion.o treasure.o restoreHealth.o boostAtk.o boostDef.o poisonHealth.o woundAtk.o woundDef.o dragonHoard.o merchantHoard.o normalGold.o smallGold.o
OBJECTS= ${MAINOBJ} ${FLOOROBJ} ${CHAROBJ} ${PLAYEROBJ} ${NPCOBJ} ${ITEMOBJ}
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -g ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}
clean:
	rm *.o cc3k *.d
.PHONY: clean
