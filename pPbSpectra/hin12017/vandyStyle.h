#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "TString.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TMath.h"
#include "TTree.h"
#include "TChain.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TLine.h"
#include "TAxis.h"

void vandyStyle(){

cout << "Welcome to Vandy Heavy Ion group!! " << endl;

}

TCanvas* makeCanvas(const char* name, const char *title, bool doLogx == false, bool doLogy == true ){
	
	// Start with a canvas
	TCanvas *canvas = new TCanvas(name,title, 1, 1 ,600 ,600 );
	// General overall stuff
	canvas->SetFillColor      (0);
	canvas->SetBorderMode     (0);
	canvas->SetBorderSize     (10);
	// Set margins to reasonable defaults
	canvas->SetLeftMargin     (0.13);
	canvas->SetRightMargin    (0.10);
	canvas->SetTopMargin      (0.10);
	canvas->SetBottomMargin   (0.13);
	// Setup a frame which makes sense
	canvas->SetFrameFillStyle (0);
	canvas->SetFrameLineStyle (0);
	canvas->SetFrameBorderMode(0);
	canvas->SetFrameBorderSize(10);
	canvas->SetFrameFillStyle (0);
	canvas->SetFrameLineStyle (0);
	canvas->SetFrameBorderMode(0);
	canvas->SetFrameBorderSize(10);

	if( doLogy == true ) gPad->SetLogy(1);
	if( doLogx == true ) gPad->SetLogx(1);
	
	gPad->SetTicks();

	return canvas;
}

TCanvas* makeMultiCanvas(const char* name, 
						 const char* title,
						 int nRows,
						 int nColumns
){

	double ratio = nRows/nColumns;

	TCanvas* canvas = new TCanvas( name, title, 1, 1, 400*nRows, 350*nColumns );
	canvas->SetFillColor      (0);
	canvas->SetBorderMode     (0);
	canvas->SetBorderSize     (10);
	// Set margins to reasonable defaults
	canvas->SetLeftMargin     (0.30);
	canvas->SetRightMargin    (0.10);
	canvas->SetTopMargin      (0.10);
	canvas->SetBottomMargin   (0.30);
	// Setup a frame which makes sense
	canvas->SetFrameFillStyle (0);
	canvas->SetFrameLineStyle (0);
	canvas->SetFrameBorderMode(0);
	canvas->SetFrameBorderSize(10);
	canvas->SetFrameFillStyle (0);
	canvas->SetFrameLineStyle (0);
	canvas->SetFrameBorderMode(0);
	canvas->SetFrameBorderSize(10);
 	
 	canvas->Divide(nRows,nColumns,0.01,0.01);
 	//canvas->Divide(nRows,nColumns,0.0,0.0);

 	//gPad->SetLeftMargin(0.3);
 	//gPad->SetBottomMargin(0.3);
	return canvas;

}

void saveCanvas(TCanvas* c, TString dir, TString filename)
{
   TDatime* date = new TDatime();
   c->Print(Form("../%s/%s_%d.eps",dir.Data(),filename.Data(),date->GetDate()));
   c->Print(Form("../%s/%s_%d.gif",dir.Data(),filename.Data(),date->GetDate()));
   c->Print(Form("../%s/%s_%d.pdf",dir.Data(),filename.Data(),date->GetDate()));
   c->Print(Form("../%s/%s_%d.C",dir.Data(),filename.Data(),date->GetDate()));
}

void initSubPad(TPad* pad, int i)
{
  //printf("Pad: %p, index: %d\n",pad,i);

  pad->cd(i);
  TPad *tmpPad = pad->GetPad(i);
  tmpPad->SetLeftMargin  (0.20);
  tmpPad->SetTopMargin   (0.06);
  tmpPad->SetRightMargin (0.08);
  tmpPad->SetBottomMargin(0.15);
  return;
}

TH1D* makeHist(const char*name, const char*title, const char*xtit, const char*ytit, const int nBins, const double lower, const double higher, EColor color = kBlack ){

	TH1D* temp = new TH1D(name, title, nBins, lower, higher);
	
	temp->SetMarkerSize(1.0);
	temp->SetMarkerStyle(20);
	temp->SetMarkerColor(color);
	temp->SetLineColor(color);
	temp->SetStats(kFALSE);

	temp->GetXaxis()->SetTitle( xtit );
	temp->GetXaxis()->SetTitleSize(0.05);
	temp->GetXaxis()->SetTitleFont(42);
	temp->GetXaxis()->SetTitleOffset(1.25);
	temp->GetXaxis()->SetLabelSize(0.05);
	temp->GetXaxis()->SetLabelOffset(0.01);
	temp->GetXaxis()->SetLabelFont(42);
	temp->GetXaxis()->SetLabelColor(kBlack);
	temp->GetXaxis()->CenterTitle();

	temp->GetYaxis()->SetTitle( ytit );
	temp->GetYaxis()->SetTitleSize(0.05);
	temp->GetYaxis()->SetTitleFont(42);
	temp->GetYaxis()->SetTitleOffset(1.4);
	temp->GetYaxis()->SetLabelSize(0.05);
	temp->GetYaxis()->SetLabelOffset(0.01);
	temp->GetYaxis()->SetLabelFont(42);
	temp->GetYaxis()->SetLabelColor(kBlack);
	temp->GetYaxis()->CenterTitle();

	return temp;
}

void fixedFontHist1D(TH1 * h, Float_t xoffset=1.5, Float_t yoffset=2.3)
{
  h->SetLabelFont(43,"X");
  h->SetLabelFont(43,"Y");
  //h->SetLabelOffset(0.01);
  h->SetLabelSize(16);
  h->SetTitleFont(43);
  h->SetTitleSize(20);
  h->SetLabelSize(15,"Y");
  h->SetTitleFont(43,"Y");
  h->SetTitleSize(20,"Y");
  h->SetTitleOffset(xoffset,"X");
  h->SetTitleOffset(yoffset,"Y");
  h->GetXaxis()->CenterTitle();
  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetNdivisions(506); 

  h->SetStats(0);
  //h->SetBarWidth(0.8);
  //h->SetBarOffset(0.1);
  //h->SetTickLength(0.01);
  //h->SetAxisRange(1e-13,950,"Y");


}

TH2D* make2DHist( const char*name, 
			      const char*title, 
			      const char*xtit, 
			      const char*ytit,
			      const int nxbins,
			      const double xlow, 
			      const double xhigh,
			      const int nybins,
			      const double ylow, 
			      const double yhigh
){

	TH2D* temp2D = new TH2D(name, title, nxbins, xlow, xhigh, nybins, ylow, yhigh);

	temp2D->SetMarkerSize(1.0);
	temp2D->SetMarkerStyle(20);
	temp2D->SetMarkerColor(kBlack);
	temp2D->SetLineColor(kBlack);
	temp2D->SetStats(kFALSE);

	temp2D->GetXaxis()->SetTitle( xtit );
	temp2D->GetXaxis()->SetTitleSize(0.04);
	temp2D->GetXaxis()->SetTitleFont(42);
	temp2D->GetXaxis()->SetTitleOffset(1.4);
	temp2D->GetXaxis()->SetLabelSize(0.04);
	temp2D->GetXaxis()->SetLabelOffset(0.01);
	temp2D->GetXaxis()->SetLabelFont(42);
	temp2D->GetXaxis()->SetLabelColor(kBlack);

	temp2D->GetYaxis()->SetTitle( ytit );
	temp2D->GetYaxis()->SetTitleSize(0.04);
	temp2D->GetYaxis()->SetTitleFont(42);
	temp2D->GetYaxis()->SetTitleOffset(1.7);
	temp2D->GetYaxis()->SetLabelSize(0.04);
	temp2D->GetYaxis()->SetLabelOffset(0.01);
	temp2D->GetYaxis()->SetLabelFont(42);
	temp2D->GetYaxis()->SetLabelColor(kBlack);

	return temp2D;

}

void fixedFontHist(TH2D * h, Float_t xoffset=0.9, Float_t yoffset=2.7)
{
  h->SetLabelFont(43,"X");
  h->SetLabelFont(43,"Y");
  //h->SetLabelOffset(0.01);
  h->SetLabelSize(16);
  h->SetTitleFont(43);
  h->SetTitleSize(20);
  h->SetLabelSize(15,"Y");
  h->SetTitleFont(43,"Y");
  h->SetTitleSize(17,"Y");
  h->SetTitleOffset(xoffset,"X");
  h->SetTitleOffset(yoffset,"Y");
  h->GetXaxis()->CenterTitle();
  h->GetYaxis()->CenterTitle();
}

TLegend* makeLegend(){

	TLegend *w2 = new TLegend(0.65,0.15,0.90,0.45);
	w2->SetLineColor(kWhite);
	w2->SetFillColor(0);
	return w2;

}

TGraphAsymmErrors* makeEfficiency(TH1D* hist1, TH1D* hist2, const char*Draw == "cp", EColor color = kBlack  ){

	TGraphAsymmErrors* temp = new TGraphAsymmErrors();
	temp->Divide( hist1, hist2, Draw );
	temp->SetMarkerStyle(20);
	temp->SetMarkerColor(color);
	temp->SetLineColor(color);

	return temp;

}

TLatex* makeLatex(const char* txt,  double x, double y){

	TLatex* r = new TLatex(x, y, txt);
	r->SetTextSize(0.05);
	r->SetNDC();
	return r;

}




