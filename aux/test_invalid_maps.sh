MAP_DIR='./assets/maps/invalid'
MAPS=$(ls "${MAP_DIR}")

test_map() {
	echo Testing "$1"
	./so_long "$1"
}

for map in $MAPS; do
	test_map "$map"
	echo
done
