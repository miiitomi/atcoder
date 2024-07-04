pwd = "/workspaces/atcoder/library"
input_path = pwd+"/a.cpp"    # TODO: write file name
output_path = pwd+"/01.txt"

def main():
    with open(input_path, 'r') as fr:
        l = [ s.rstrip() for s in fr.readlines()]
        with open(output_path, 'w') as f:
            f.write('"' + '",\n"'.join(l) + '"')

if __name__ == "__main__":
    main()
