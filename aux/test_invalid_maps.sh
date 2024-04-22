MAP_DIR='./assets/maps/invalid'
MAPS=$(ls "${MAP_DIR}")

VALGRIND="valgrind --leak-check=full"

for map in $MAPS; do
	echo Testing "$map"
	./so_long "$map"
	echo
	echo Valgrind output
	$VALGRIND ./so_long "$map" 1> /dev/null
	echo
done
