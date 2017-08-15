from __future__ import print_function
import datetime
import requests

def time_from(a, b, c):
    return int(datetime.date(a, b, c).strftime("%s"))

def time_to_week_day(x):
    return datetime.datetime.fromtimestamp(x).weekday()

def time_to_str(x):
    return datetime.datetime.fromtimestamp(x).strftime('%Y/%m/%d %H:%M:%S')

def getjson():
    return requests.get('http://codeforces.com/api/contest.list?gym=false').json()

all = getjson()

while True:
    sy, sm, sd = map(int, raw_input('start - ano/mes/dia: ').split())
    
    fy, fm, fd = map(int, raw_input('end - ano/mes/dia: ').split())

    start = time_from(sy, sm, sd)
    end = time_from(fy, fm, fd)

    ans = 1
    for x in all['result']:
        if x['name'].find('Div. 2') != -1:
            if x['startTimeSeconds'] >= start and x['startTimeSeconds'] <= end:
                if time_to_week_day(x['startTimeSeconds']) >= 5:
                    ans = ans + 1
                    p = str(x['id'])
                    p += ' '
                    p += str(time_to_str(x['startTimeSeconds']))
                    print(p)

    print(ans)



