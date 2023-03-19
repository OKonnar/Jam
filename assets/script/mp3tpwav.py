import os
from pydub import AudioSegment

def convert_mp3_to_wav():
    mp3_files = [f for f in os.listdir("./") if f.endswith(".mp3")]

    for mp3_file in mp3_files:
        input_file = os.path.join("./", mp3_file)
        output_file = os.path.join("./", mp3_file.replace(".mp3", ".wav"))

        audio = AudioSegment.from_mp3(input_file)
        audio.export(output_file, format="wav")
        print(f"Converted {input_file} to {output_file}")

if __name__ == "__main__":
    convert_mp3_to_wav()
