pwd = "/Users/miiitomi/kyopuro/atcoder/library"
input_path = pwd+"/rerooting_tree.cpp"
output_path = pwd+"/out.txt"

def main():
    with open(input_path, 'r') as fr:
        l = [ s.rstrip() for s in fr.readlines()]
        with open(output_path, 'w') as f:
            f.write('"' + '",\n"'.join(l) + '"')

if __name__ == "__main__":
    main()
