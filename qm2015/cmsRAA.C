#if !defined(__CINT__) || defined(__MAKECINT__)
#include <Riostream.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "TROOT.h"
#include "TStyle.h"

#include "TFile.h"
#include "TBox.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TH1.h"
#include "TH2D.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TLine.h"

#endif
void cmsRAA(int version = 0)
{
  
  /*** Get data points ***/
  /* c-jet RpA */
  TFile *_file0 = TFile::Open("dataOverPythia_CJet.root");
  TH1D * hpARatio = (TH1D*)_file0->Get("hpARatio");
  TGraphErrors * systErrRatiopA = (TGraphErrors*)_file0->Get("systErrRatiopA");
  
  /* b-jet RpA */
  TFile *_file1 = TFile::Open("RpA_BJet_Output.root");
  TGraphErrors * RpA_SystErr_bin0 = (TGraphErrors*)_file1->Get("RpA_SystErr_bin0");
  TGraphErrors * RpA_SystErr_bin1 = (TGraphErrors*)_file1->Get("RpA_SystErr_bin1");
  TGraphErrors * RpA_SystErr_bin2 = (TGraphErrors*)_file1->Get("RpA_SystErr_bin2");
  TGraphErrors * RpA_SystErr_bin3 = (TGraphErrors*)_file1->Get("RpA_SystErr_bin3");
  TGraphErrors * RpA_SystErr_bin4 = (TGraphErrors*)_file1->Get("RpA_SystErr_bin4");
  TGraphErrors * RpA_SystErr_bin5 = (TGraphErrors*)_file1->Get("RpA_SystErr_bin5");
  TGraphErrors * RpA_SystErr_bin6 = (TGraphErrors*)_file1->Get("RpA_SystErr_bin6");
  TH1D * RpA = (TH1D*) _file1->Get("RpA");

  /* b-jet RAA */
  double p8860_d10x1y1_xval[] = { 85.0, 100.0, 120.0, 150.0, 210.0 };
  double p8860_d10x1y1_xerrminus[] = { 5.0, 10.0, 10.0, 20.0, 40.0 };
  double p8860_d10x1y1_xerrminus0[] = { .0, .0, .0, .0, .0 };
  double p8860_d10x1y1_xerrplus[] = { 5.0, 10.0, 10.0, 20.0, 40.0 };
  double p8860_d10x1y1_xerrplus0[] = { .0, .0, .0, .0, .0 };
  double p8860_d10x1y1_yval[] = { 0.3927, 0.3277, 0.4598, 0.4034, 0.4214 };
  double p8860_d10x1y1_yerrminus[] = { 0.11368698254417697, 0.10840963979277857, 0.15293086673395925, 0.18480489712126139, 0.34232354578673085 };
  double p8860_d10x1y1_yerrplus[] = { 0.11368698254417697, 0.10840963979277857, 0.15293086673395925, 0.18480489712126139, 0.34232354578673085 };
  double p8860_d10x1y1_ystatminus[] = { 0.0672, 0.0567, 0.0849, 0.1038, 0.201 };
  double p8860_d10x1y1_ystatplus[] = { 0.0672, 0.0567, 0.0849, 0.1038, 0.201 };
  int p8860_d10x1y1_numpoints = 5;
  TGraphAsymmErrors *p8860_d10x1y1 = new TGraphAsymmErrors(p8860_d10x1y1_numpoints, p8860_d10x1y1_xval, p8860_d10x1y1_yval, p8860_d10x1y1_xerrminus, p8860_d10x1y1_xerrplus, p8860_d10x1y1_ystatminus, p8860_d10x1y1_ystatplus);
  TGraphAsymmErrors *points = new TGraphAsymmErrors(p8860_d10x1y1_numpoints, p8860_d10x1y1_xval, p8860_d10x1y1_yval, p8860_d10x1y1_xerrminus0, p8860_d10x1y1_xerrplus0, p8860_d10x1y1_yerrminus, p8860_d10x1y1_yerrplus);

  /*** Define canvas and histogram pad ***/
  TCanvas * c1 = new TCanvas("c1","c1",600,600);
  TH2D * dummy = new TH2D("dummy",";p_{T} [GeV];RAA",1,0.1,260,1,0.1,2.3);
  dummy->GetYaxis()->CenterTitle();
  dummy->GetXaxis()->CenterTitle();
  cout<<dummy->GetXaxis()->GetTitleSize()<<endl;
  cout<<dummy->GetXaxis()->GetLabelSize()<<endl;
  dummy->GetXaxis()->SetTitleSize(0.055);
  dummy->GetXaxis()->SetLabelSize(0.055);
  dummy->GetYaxis()->SetTitleSize(0.055);
  dummy->GetYaxis()->SetLabelSize(0.055);
  dummy->Draw();

  
  /*** Draw Points ***/

  /* draw c-jet RpA */
  hpARatio->SetMarkerStyle(kFullSquare);
  systErrRatiopA->SetFillStyle(1001);
  systErrRatiopA->SetFillColor(TColor::GetColor("#00FF60"));
  systErrRatiopA->Draw("5 same");
  hpARatio->Draw("Psame");

  /* draw b-jet RpA */
  RpA_SystErr_bin0->SetFillStyle(1001);
  RpA_SystErr_bin0->SetFillColor(TColor::GetColor("#ba8a98"));
  RpA_SystErr_bin0->Draw("5 same");
  RpA_SystErr_bin1->SetFillStyle(1001);
  RpA_SystErr_bin1->SetFillColor(TColor::GetColor("#ba8a98"));
  RpA_SystErr_bin1->Draw("5 same");
  RpA_SystErr_bin2->SetFillStyle(1001);
  RpA_SystErr_bin2->SetFillColor(TColor::GetColor("#ba8a98"));
  RpA_SystErr_bin2->Draw("5 same");
  RpA_SystErr_bin3->SetFillStyle(1001);
  RpA_SystErr_bin3->SetFillColor(TColor::GetColor("#ba8a98"));
  RpA_SystErr_bin3->Draw("5 same");
  RpA_SystErr_bin4->SetFillStyle(1001);
  RpA_SystErr_bin4->SetFillColor(TColor::GetColor("#ba8a98"));
  RpA_SystErr_bin4->Draw("5 same");
  RpA_SystErr_bin5->SetFillStyle(1001);
  RpA_SystErr_bin5->SetFillColor(TColor::GetColor("#ba8a98"));
  RpA_SystErr_bin5->Draw("5 same");
  RpA_SystErr_bin6->SetFillStyle(1001);
  RpA_SystErr_bin6->SetFillColor(TColor::GetColor("#ba8a98"));
  RpA_SystErr_bin6->Draw("5 same");
  RpA->Draw("same");

  /* draw b-jet RAA */
  p8860_d10x1y1->SetFillStyle(1001);
  p8860_d10x1y1->SetFillColor(TColor::GetColor("#33ccff"));
  p8860_d10x1y1->Draw("5 same");
  points->Draw("PE same");

  
  /*** Draw Legend ***/
  TLegend *leg = new TLegend(0.47,0.75,0.95,0.90,NULL,"brNDC");
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->SetTextSize(0.029);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(19);
  leg->SetFillStyle(0);
  
  /* draw c-jet RpA */
  TLegendEntry *e_cjetrpa=leg->AddEntry("cjetrpa","c-jet RpA Data/PYTHIA Z2","lpf");
  e_cjetrpa->SetFillColor(TColor::GetColor("#00FF60"));
  e_cjetrpa->SetFillStyle(1001);
  e_cjetrpa->SetLineColor(1);
  e_cjetrpa->SetLineStyle(1);
  e_cjetrpa->SetLineWidth(1);
  e_cjetrpa->SetMarkerStyle(kFullSquare);
  e_cjetrpa->SetMarkerSize(1);

  /* draw b-jet RpA */
  TLegendEntry *e_bjetrpa=leg->AddEntry("bjetrpa","b-jet RpA Data/PYTHIA Z2","lpf");
  e_bjetrpa->SetFillColor(TColor::GetColor("#ba8a98"));
  e_bjetrpa->SetFillStyle(1001);
  e_bjetrpa->SetLineColor(1);
  e_bjetrpa->SetLineStyle(1);
  e_bjetrpa->SetLineWidth(1);
  e_bjetrpa->SetMarkerStyle(kFullCircle);
  e_bjetrpa->SetMarkerSize(1);
  
  /* draw b-jet RAA */
  TLegendEntry *e_bjetraa=leg->AddEntry("bjetraa","b-jet RAA","lpf");
  e_bjetraa->SetFillColor(TColor::GetColor("#33ccff"));
  e_bjetraa->SetFillStyle(1001);
  e_bjetraa->SetLineColor(1);
  e_bjetraa->SetLineStyle(1);
  e_bjetraa->SetLineWidth(1);
  e_bjetraa->SetMarkerStyle(kFullCircle);
  e_bjetraa->SetMarkerSize(1);
  
  leg->Draw();

}
  
