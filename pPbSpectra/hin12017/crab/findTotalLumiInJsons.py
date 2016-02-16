import json
from pprint import pprint

with open('Cert_262081_262328_5TeV_PromptReco_Collisions15_25ns_JSON.txt') as json_data:
    data = json.load(json_data)
#    pprint(data)

runs = data.keys()
lumis = data.values()

#print data
#print runs
#print len(runs)
sum=0
for i in range(0, len(runs)):
    for j in range(0, len(lumis[i])):
        nLumis = (lumis[i][j][1] - lumis[i][j][0]) + 1
        sum += nLumis
        #print nLumis

print "Total run =", len(runs)
print "Total Lumi =", sum

#run = data['262328']
#print run[0][1]



