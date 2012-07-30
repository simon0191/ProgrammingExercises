for file in *; do
   if [ -d $file ]; then
		find ./$file -perm +100 -type f -delete;
   fi
done

