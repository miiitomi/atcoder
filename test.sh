problem_name=$1
ext_name=$2
file=$3
relative_file_dir_name=$4
contest_name=${relative_file_dir_name##*/}
test_dir=samples/${contest_name}/${problem_name}
ac_library_path=/workspaces/atcoder/ac-library
contest_type=`echo ${relative_file_dir_name%/*}`

if [ ${contest_name} = tessoku-book ];
then
    url=https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_${problem_name}
elif [ ${contest_name} = math-and-algorithm ];
then
    url=https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_${problem_name}
elif [ ${contest_type} = mayocon ] || [ ${contest_type} = mosoonv ] || [ ${contest_type} = miiitomi ] || [ ${contest_type} = typical90 ];
then
    url=`head -n 1 ${file}`
    url=${url:3}
else
    url=https://atcoder.jp/contests/${contest_name}/tasks/${contest_name}_${problem_name}
fi

# make sample directory
if [ ! -e ${test_dir} ]; then
    oj dl -d ${test_dir} ${url}
fi

# test
g++ ${file} -std=gnu++23 -Wall -Wextra -O2 -I ${ac_library_path} && oj test -c "./a.out" -d ${test_dir}

rm -rf samples/
rm "./a.out"
