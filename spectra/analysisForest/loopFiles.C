#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TrackSlurm.C"
void loopFiles()
{
    const TString list = "./fileList/PU1.txt";
    int datasetFlag = 1; //1 for MB, 2 for LowJet, 3 for Jet80

    ifstream file(list);
    std::string line;
    vector<string> lineArray;
    while (std::getline(file, line))
    {
        lineArray.push_back(line);
    }
    file.close();
    //cout<<lineArray[0]<<endl; 
   
    gROOT->ProcessLine(".L TrackSlurm.C+");

    int start=atoi(getenv("START"));
    int end=atoi(getenv("END"));
    TString runjobfile;
    TString inFileName;
    TString outFileName;

    for(int i=start;i<end;i++)
    {    
        inFileName = lineArray[i];
        outFileName = Form("RpA_PU%d_output_%d_histograms.root",datasetFlag,i);
        //runjobfile = ".x genTracks.C(\"" + lineArray[i] + Form("\", %d, %d", datasetFlag, i)+ ")";
        cout<<endl<<"START "<<i<<" th file: "<<lineArray[i]<<endl;
        //TrackSlurm *tracks = new TrackSlurm(inFileName);
        TrackSlurm *tracks = new TrackSlurm();
        //tracks->beginJob();
        tracks->getHistograms(inFileName, outFileName);
        //tracks->endJob(outFileName)
        cout<<"END "<<i<<" th file: "<<lineArray[i]<<endl;

    }
    //remove("genTracks_C.d");
    //remove("genTracks_C_ACLiC_dict_rdict.pcm");
    //remove("genTracks_C.so");

}

