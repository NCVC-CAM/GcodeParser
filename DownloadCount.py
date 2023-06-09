import requests

r = requests.get('https://api.github.com/repos/NCVC-CAM/GcodeParser/releases')

for item in sorted(r.json(), key=lambda k: k['name']):
    print("ReleaseName: ", item["name"])
    for detail in item["assets"]:
        print(" FileName: ", detail["name"], end='')
        print(" download_count=", detail["download_count"])
    print("")
