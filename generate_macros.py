import sys

def generate_macros(cfg_file, output_file):
    try:
        with open(cfg_file, 'r') as f:
            lines = f.readlines()

        with open(output_file, 'w') as f:
            f.write("/* Auto-generated from config.cfg */\n")
            for line in lines:
                if line.strip() and not line.startswith("#"):  # 跳过空行和注释
                    parts = line.split()
                    if len(parts) == 2:
                        key, value = parts
                        f.write(f"#define {key} {value}\n")
        print(f"{output_file} generated successfully.")
    except Exception as e:
        print(f"Error generating {output_file}: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python generate_macros.py <cfg_file> <output_file>")
        sys.exit(1)

    cfg_file = sys.argv[1]
    output_file = sys.argv[2]
    
    generate_macros(cfg_file, output_file)
