file_no_extension=$1
file=$2
file_dir_name=$3
ac_library_path=/workspaces/atcoder/ac-library
test_dir=./test_${file_no_extension}

cd ${file_dir_name}

if [ -d ${test_dir} ];
then
    rm -rf ${test_dir}
fi

g++ ${file_no_extension}_generate.cpp -std=gnu++23 -I ${ac_library_path} -I /opt/homebrew/Cellar/boost/1.87.0/include/ -o ${file_no_extension}_generate.out
oj g/i -d ${test_dir} ./${file_no_extension}_generate.out 10
rm ${file_no_extension}_generate.out

g++ ./${file_no_extension}_naive.cpp -std=gnu++23 -I ${ac_library_path} -I /opt/homebrew/Cellar/boost/1.87.0/include/ -o ./${file_no_extension}_naive.out
oj g/o -c ./${file_no_extension}_naive.out -d ${test_dir}
rm ./${file_no_extension}_naive.out

g++ ${file} -std=gnu++23 -Wall -Wextra -O2 -I ${ac_library_path} -I /opt/homebrew/Cellar/boost/1.87.0/include/ -o ./${file_no_extension}.out
oj t -d ${test_dir} -c ./${file_no_extension}.out
rm ./${file_no_extension}.out
