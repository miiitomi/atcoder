file_no_extension=$1
file=$2
file_dir_name=$3
ac_library_path=~/kyopuro/atcoder/ac-library
bin_dir=${file_dir_name}/bin
result_dir=${file_dir_name}/result
result_file=${result_dir}/${file_no_extension}.txt

cd ${file_dir_name}

if [ ! -e ${bin_dir} ]; then
    mkdir ${bin_dir}
fi

if [ ! -e ${file_dir_name}/out ]; then
    mkdir ${file_dir_name}/out
fi

if [ ! -e ${result_dir} ]; then
    mkdir ${result_dir}
fi

g++ ${file} -std=c++14 -I ${ac_library_path} -o ${bin_dir}/${file_no_extension}.out

for i in `seq -w 0 9`
do
    if [ ${i} -eq 0 ]; then
        ${bin_dir}/${file_no_extension}.out < ${file_dir_name}/in/000${i}.txt > ${file_dir_name}/out/000${i}_${file_no_extension}.txt
        cargo run -q --release --bin vis ${file_dir_name}/in/000${i}.txt ${file_dir_name}/out/000${i}_${file_no_extension}.txt > ${result_file}
    else
        ${bin_dir}/${file_no_extension}.out < ${file_dir_name}/in/000${i}.txt > ${file_dir_name}/out/000${i}_${file_no_extension}.txt
        cargo run -q --release --bin vis ${file_dir_name}/in/000${i}.txt ${file_dir_name}/out/000${i}_${file_no_extension}.txt >> ${result_file}
    fi
done

sum=0

while read x y z; do
    sum=`expr ${sum} + ${z}`
done < ${result_file}

echo Total Score = ${sum} >> ${result_file}
echo ${file_no_extension} : Total Score = ${sum}
