echo "ENter numbers"
read -a inputArrayOfNumbers # input separated by spaces and not by carriage r
echo -n "Entered input is…"
for i in ${inputArrayOfNumbers[@]} ; do
echo -n $i " "
done
