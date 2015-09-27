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
void bcjetRAA(int version = 0)
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
  TH2D * dummy = new TH2D("dummy",";p_{T} [GeV];Nuclear Modification Factor",1,0,260,1,0,2.5);
  dummy->GetYaxis()->CenterTitle();
  dummy->GetXaxis()->CenterTitle();
  dummy->GetXaxis()->SetTitleFont(42);
  dummy->GetYaxis()->SetTitleFont(42);
  dummy->GetYaxis()->SetTitleOffset(1.2);
  dummy->GetXaxis()->SetTitleSize(0.055);
  dummy->GetXaxis()->SetLabelSize(0.055);
  dummy->GetYaxis()->SetTitleSize(0.055);
  dummy->GetYaxis()->SetLabelSize(0.055);
  dummy->Draw();

  TLine * lone = new TLine(0,1,250,1);
  lone->SetLineStyle(7);
  lone->Draw();

  
  /*** Draw Points ***/

  /* draw c-jet RpA */
  hpARatio->SetMarkerStyle(kFullSquare);
  systErrRatiopA->SetLineWidth(1);
  systErrRatiopA->SetFillStyle(1001);
  systErrRatiopA->SetFillColor(TColor::GetColor("#ba8a98"));
  systErrRatiopA->Draw("5 same");
  hpARatio->Draw("Psame");

  /* draw b-jet RpA */
  RpA_SystErr_bin0->SetLineWidth(1);
  RpA_SystErr_bin0->SetFillStyle(1001);
  RpA_SystErr_bin0->SetFillColor(TColor::GetColor("#66FFFF"));
  RpA_SystErr_bin0->Draw("5 same");
  RpA_SystErr_bin1->SetLineWidth(1);
  RpA_SystErr_bin1->SetFillStyle(1001);
  RpA_SystErr_bin1->SetFillColor(TColor::GetColor("#66FFFF"));
  RpA_SystErr_bin1->Draw("5 same");
  RpA_SystErr_bin2->SetLineWidth(1);
  RpA_SystErr_bin2->SetFillStyle(1001);
  RpA_SystErr_bin2->SetFillColor(TColor::GetColor("#66FFFF"));
  RpA_SystErr_bin2->Draw("5 same");
  RpA_SystErr_bin3->SetLineWidth(1);
  RpA_SystErr_bin3->SetFillStyle(1001);
  RpA_SystErr_bin3->SetFillColor(TColor::GetColor("#66FFFF"));
  RpA_SystErr_bin3->Draw("5 same");
  RpA_SystErr_bin4->SetLineWidth(1);
  RpA_SystErr_bin4->SetFillStyle(1001);
  RpA_SystErr_bin4->SetFillColor(TColor::GetColor("#66FFFF"));
  RpA_SystErr_bin4->Draw("5 same");
  RpA_SystErr_bin5->SetLineWidth(1);
  RpA_SystErr_bin5->SetFillStyle(1001);
  RpA_SystErr_bin5->SetFillColor(TColor::GetColor("#66FFFF"));
  RpA_SystErr_bin5->Draw("5 same");
  RpA_SystErr_bin6->SetLineWidth(1);
  RpA_SystErr_bin6->SetFillStyle(1001);
  RpA_SystErr_bin6->SetFillColor(TColor::GetColor("#66FFFF"));
  RpA_SystErr_bin6->Draw("5 same");
  RpA->Draw("same");

  /* draw b-jet RAA */
  p8860_d10x1y1->SetFillStyle(1001);
  p8860_d10x1y1->SetFillColor(TColor::GetColor("#CCCCCC"));
  p8860_d10x1y1->Draw("5 same");
  points->Draw("PE same");

  TLatex * toptext = new TLatex( 0.23, 0.955, Form("150 #mub^{-1} (PbPb 2.76 TeV), 35 nb^{-1} (pPb 5.02 TeV)"));
  toptext->SetNDC(1);
  toptext->SetTextSize(toptext->GetTextSize()*1.05);
  toptext->Draw("same");

  TLatex * cms = new TLatex( 0.25, 0.88, Form("#font[62]{CMS}"));
  cms->SetNDC(1);
  cms->SetTextSize(cms->GetTextSize()*1.21);
  cms->Draw("same");
  
  TLatex * prelim = new TLatex( 0.35, 0.88, Form("#font[72]{Preliminary}"));
  prelim->SetNDC(1);
  prelim->SetTextSize(prelim->GetTextSize()*1.21);
  prelim->SetTextColor(TColor::GetColor("#8E0000"));
  prelim->Draw("same");
  
  TBox *pPb_lumi_uncertainty = new TBox(0.9,0.964,15,1.036);
  pPb_lumi_uncertainty->SetFillColor(TColor::GetColor("#006600"));
  pPb_lumi_uncertainty->SetFillStyle(1001);
  TBox *refernce_uncertainty = new TBox(0.9,0.78,15,1.22);
  refernce_uncertainty->SetFillColor(TColor::GetColor("#ff6666"));
  refernce_uncertainty->SetFillStyle(1001);

  refernce_uncertainty->Draw("same");
  pPb_lumi_uncertainty->Draw("same");
  
  
  /*** Draw Legend ***/
  TLegend *leg = new TLegend(0.22,0.65,0.95,0.85,NULL,"brNDC");
  leg->SetBorderSize(0);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(19);
  leg->SetFillStyle(0);
  float legend_text_size=0.032;
  
  /* draw c-jet RpA */
  TLegendEntry *e_cjetrpa=leg->AddEntry("cjetrpa","c-jet R_{pA} Data/PYTHIA Z2","lpf");
  e_cjetrpa->SetFillColor(TColor::GetColor("#ba8a98"));
  e_cjetrpa->SetFillStyle(1001);
  e_cjetrpa->SetTextSize(legend_text_size);
  e_cjetrpa->SetTextFont(42);
  e_cjetrpa->SetTextColor(TColor::GetColor("#8E0000"));
  e_cjetrpa->SetLineColor(1);
  e_cjetrpa->SetLineStyle(1);
  e_cjetrpa->SetLineWidth(1);
  e_cjetrpa->SetMarkerStyle(kFullSquare);
  e_cjetrpa->SetMarkerSize(1);

  /* draw b-jet RpA */
  TLegendEntry *e_bjetrpa=leg->AddEntry("bjetrpa","b-jet R_{pA} Data/PYTHIA Z2","lpf");
  e_bjetrpa->SetFillColor(TColor::GetColor("#66FFFF"));
  e_bjetrpa->SetFillStyle(1001);
  e_bjetrpa->SetTextSize(legend_text_size);
  e_bjetrpa->SetTextFont(42);
  e_bjetrpa->SetTextColor(TColor::GetColor("#8E0000"));
  e_bjetrpa->SetLineColor(1);
  e_bjetrpa->SetLineStyle(1);
  e_bjetrpa->SetLineWidth(1);
  e_bjetrpa->SetMarkerStyle(kFullCircle);
  e_bjetrpa->SetMarkerSize(1);
  
  /* draw b-jet RAA */
  TLegendEntry *e_bjetraa=leg->AddEntry("bjetraa","b-jet R_{AA}","lpf");
  e_bjetraa->SetFillColor(TColor::GetColor("#CCCCCC"));
  e_bjetraa->SetFillStyle(1001);
  e_bjetraa->SetTextSize(legend_text_size);
  e_bjetraa->SetTextFont(42);
  e_bjetraa->SetLineColor(1);
  e_bjetraa->SetLineStyle(1);
  e_bjetraa->SetLineWidth(1);
  e_bjetraa->SetMarkerStyle(kFullCircle);
  e_bjetraa->SetMarkerSize(1);
  
  /* lumi uncertainty legend */
  TLegendEntry *e_lumiuncert=leg->AddEntry("lumiuncert","pPb Luminosity Uncertainty","f");
  e_lumiuncert->SetFillColor(TColor::GetColor("#006600"));
  e_lumiuncert->SetFillStyle(1001);
  e_lumiuncert->SetTextSize(legend_text_size);
  e_lumiuncert->SetTextFont(42);
  e_lumiuncert->SetLineWidth(0);
  e_lumiuncert->SetMarkerStyle(kFullCircle);
  e_lumiuncert->SetMarkerSize(1);
  
  /* refernce uncertainty legend*/
  TLegendEntry *e_refuncert=leg->AddEntry("refuncert","Reference Uncertainty","f");
  e_refuncert->SetFillColor(TColor::GetColor("#ff6666"));
  e_refuncert->SetFillStyle(1001);
  e_refuncert->SetTextSize(legend_text_size);
  e_refuncert->SetTextFont(42);
  e_refuncert->SetLineWidth(0);
  e_refuncert->SetMarkerStyle(kFullCircle);
  e_refuncert->SetMarkerSize(1);
  
  leg->Draw();

}
  
