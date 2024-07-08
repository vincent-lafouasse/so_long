MAP_DIR='./assets/maps/invalid'
MAPS=$(find "${MAP_DIR}" -type f)

VALGRIND="valgrind --leak-check=full"

for map in $MAPS; do
	echo ---------------------------------------------------------------------------------------------------
	echo Testing "$map"
	cat "$map"
	./so_long "$map"
	echo
	echo Valgrind output
	$VALGRIND ./so_long "$map"
	echo
done
