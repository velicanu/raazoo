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
void mesonRAA(int version = 0)
{
  /*** Plot configuration ***/
  float xaxis_min = 0, xaxis_max = 109, yaxis_min = 0, yaxis_max = 2.5;
  
  
  /*** Get data points ***/
  /* D meson RAA */
  // TFile *_file0 = TFile::Open("PromptRAA_D0_PbPb_spectrum_fonll_effunpre_cent0to100_ptbin12_y1_dataplusfonll.root");
  TFile *_file0 = TFile::Open("PromptRAA_D0_PbPb_spectrum_fonll_effunpre_cent0to10_ptbin12_y1_dataplusfonll.root");
  TGraphAsymmErrors * D0_fonll_raa_errorsys = (TGraphAsymmErrors*)_file0->Get("D0_fonll_raa_errorsys");
  TGraphAsymmErrors * D0_fonll_raa_errorfonll = (TGraphAsymmErrors*)_file0->Get("D0_fonll_raa_errorfonll");
  TGraphAsymmErrors * D0_fonll_raa_errordata = (TGraphAsymmErrors*)_file0->Get("D0_fonll_raa_errordata");
  TGraphAsymmErrors * D0_fonll_raa_errordata_dataextraref = (TGraphAsymmErrors*)_file0->Get("D0_fonll_raa_errordata_dataextraref");
  TGraphAsymmErrors * D0_fonll_raa_errordata_FONLLref = (TGraphAsymmErrors*)_file0->Get("D0_fonll_raa_errordata_FONLLref");
  
  /* charged hadron RAA */
  double ptBins_h[27], ptError_h[27], raa_h[27], raaStat_h[27], raaSyst_h[27], ptSystXlow_h[27], ptSystXhigh_h[27];
  ifstream inData_h; 
  TString inFile("raa_h05.dat");
  inData_h.open(inFile);
  if(inData_h.fail()) { cerr << "unable to open file raa_h05.dat for reading" << endl; exit(1); }
  Int_t j=0;
  Double_t xx_low, xx_high,raa,raa_syst, raa_stat;
  while(!inData_h.eof())
  { 
    inData_h >> xx_low >> xx_high >> raa >> raa_syst >> raa_stat;
    ptBins_h[j]   = xx_low+ (xx_high-xx_low)/2;
    raa_h[j]      = raa;
    raaStat_h[j]  = raa_syst;
    raaSyst_h[j]  = raa_stat;  
    ptSystXlow_h[j] = (xx_high-xx_low)/2;
    ptSystXhigh_h[j]= (xx_high-xx_low)/2;
    j++;
  }     
  inData_h.close();
  TGraphErrors      *hadronRaa     = new TGraphErrors(27, ptBins_h, raa_h, ptError_h, raaStat_h);
  TGraphAsymmErrors *hadronRaaSyst = new TGraphAsymmErrors(27, ptBins_h, raa_h, ptSystXlow_h,ptSystXhigh_h,raaSyst_h,raaSyst_h);
    
  
  /* B meson RpA */
  double bs_x[] = {35};
  double bs_xerr[] = {25};
  double bs_xerr0[] = {0};
  double bs_y[] = {0.93};
  double bs_ystat[] = {0.18};
  double bs_ysyst[] = {0.20};
  int nbs = 1;
  
  double b0_x[] = {12.5,17.5,40};
  double b0_xerr[] = {2.5,2.5,20};
  double b0_xerr0[] = {0,0,0};
  double b0_y[] = {0.99,0.83,1.03};
  double b0_ystat[] = {0.15,0.15,0.14};
  double b0_ysyst[] = {0.18,0.15,0.19};
  int nb0 = 3;
  
  double bp_x[] = {12.5,17.5,22.5,27.5,45};
  double bp_xerr[] = {2.5,2.5,2.5,2.5,15};
  double bp_xerr0[] = {0,0,0,0,0};
  double bp_y[] = {1.11,1.19,0.91,0.86,1.14};
  double bp_ystat[] = {0.08,0.10,0.12,0.18,0.19};
  double bp_ysyst[] = {0.17,0.17,0.13,0.12,0.17};
  int nbp = 5;
  
  TGraphErrors *bs_stat = new TGraphErrors(nbs,bs_x,bs_y,bs_xerr0,bs_ystat);
  TGraphErrors *bs_syst = new TGraphErrors(nbs,bs_x,bs_y,bs_xerr,bs_ysyst);
  TGraphErrors *b0_stat = new TGraphErrors(nb0,b0_x,b0_y,b0_xerr0,b0_ystat);
  TGraphErrors *b0_syst = new TGraphErrors(nb0,b0_x,b0_y,b0_xerr,b0_ysyst);
  TGraphErrors *bp_stat = new TGraphErrors(nbp,bp_x,bp_y,bp_xerr0,bp_ystat);
  TGraphErrors *bp_syst = new TGraphErrors(nbp,bp_x,bp_y,bp_xerr,bp_ysyst);
  
  /*** Define canvas and histogram pad ***/
  TCanvas * c1 = new TCanvas("c1","c1",600,600);
  TH2D * dummy = new TH2D("dummy",";p_{T} [GeV];Nuclear Modification Factor",1,xaxis_min,xaxis_max,1,yaxis_min,yaxis_max);
  dummy->GetYaxis()->CenterTitle();
  dummy->GetXaxis()->CenterTitle();
  dummy->GetXaxis()->SetTitleFont(42);
  dummy->GetXaxis()->SetTitleFont(42);
  dummy->GetYaxis()->SetTitleFont(42);
  dummy->GetYaxis()->SetTitleFont(42);
  dummy->GetYaxis()->SetTitleOffset(1.2);
  dummy->GetXaxis()->SetTitleSize(0.055);
  dummy->GetXaxis()->SetLabelSize(0.055);
  dummy->GetYaxis()->SetTitleSize(0.055);
  dummy->GetYaxis()->SetLabelSize(0.055);
  dummy->Draw();
  
  TLine * lone = new TLine(0,1,109,1);
  lone->SetLineStyle(7);
  lone->Draw();
  
  /*** Draw Points ***/

  
  /* draw hadron RAA */
  hadronRaa->SetMarkerStyle(kFullSquare);
  hadronRaaSyst->SetFillStyle(1001);
  hadronRaaSyst->SetFillColor(TColor::GetColor("#33ccff"));
  // hadronRaaSyst->SetFillColor(TColor::GetColor("#ba8a98"));
  hadronRaaSyst->Draw("5same");
  hadronRaa->Draw("Psame");
  // D0_fonll_raa_errordata_dataextraref->Draw("Psame");
  // D0_fonll_raa_errordata_FONLLref->Draw("Psame");

  /* draw B meson RpA */
  bs_syst->SetFillStyle(1001);
  bs_syst->SetFillColor(TColor::GetColor("#ff88ff"));
  bs_syst->Draw("5 same");
  bs_stat->Draw("PE same");

  b0_syst->SetFillStyle(1001);
  b0_syst->SetFillColor(TColor::GetColor("#ba8a98"));
  b0_syst->Draw("5 same");
  b0_stat->Draw("PE same");

  bp_syst->SetFillStyle(1001);
  bp_syst->SetFillColor(TColor::GetColor("#ffbf00"));
  bp_syst->Draw("5 same");
  bp_stat->Draw("PE same");

  /* draw D0 RAA */
  D0_fonll_raa_errorsys->SetMarkerStyle(kFullSquare);
  D0_fonll_raa_errorfonll->SetFillStyle(1001);
  D0_fonll_raa_errorfonll->SetLineWidth(1);
  D0_fonll_raa_errorfonll->SetFillColor(TColor::GetColor("#00FF60"));
  D0_fonll_raa_errorfonll->Draw("5same");
  D0_fonll_raa_errorsys->Draw("Psame");
  // D0_fonll_raa_errordata_dataextraref->Draw("Psame");
  // D0_fonll_raa_errordata_FONLLref->Draw("Psame");

  TLatex * toptext = new TLatex( 0.23, 0.955, Form("150 #mub^{-1} (PbPb 2.76 TeV), 35 nb^{-1} (pPb 5.02 TeV)"));
  toptext->SetNDC(1);
  toptext->SetTextSize(toptext->GetTextSize()*1.05);
  toptext->Draw("same");

  TLatex * cms = new TLatex( 0.25, 0.88, Form("#font[52]{CMS}"));
  cms->SetNDC(1);
  cms->SetTextSize(cms->GetTextSize()*1.21);
  cms->Draw("same");
  
  TLatex * prelim = new TLatex( 0.35, 0.88, Form("#font[62]{Preliminary}"));
  prelim->SetNDC(1);
  prelim->SetTextSize(prelim->GetTextSize()*1.21);
  prelim->SetTextColor(TColor::GetColor("#8E0000"));
  prelim->Draw("same");

  TBox *pPb_lumi_uncertainty = new TBox(0.3,0.964,5,1.036);
  pPb_lumi_uncertainty->SetFillColor(TColor::GetColor("#006600"));
  pPb_lumi_uncertainty->SetFillStyle(1001);
  // TBox *refernce_uncertainty = new TBox(0.9,0.78,15,1.22);
  // refernce_uncertainty->SetFillColor(TColor::GetColor("#ff6666"));
  // refernce_uncertainty->SetFillStyle(1001);

  // refernce_uncertainty->Draw("same");
  pPb_lumi_uncertainty->Draw("same");
  
  
  /*** Draw Legend ***/
  // TLegend *leg = new TLegend(0.35,0.65,0.95,0.85,NULL,"brNDC");
  TLegend *leg = new TLegend(0.22,0.61,0.95,0.85,NULL,"brNDC");
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->SetTextSize(0.029);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(19);
  leg->SetFillStyle(0);
  float legend_text_size=0.032;

  /* legend for D meson RAA */
  TLegendEntry *e_dmesonraa=leg->AddEntry("dmesonraa","D meson (0-10%)","lpf");
  e_dmesonraa->SetFillColor(TColor::GetColor("#00FF60"));
  e_dmesonraa->SetTextColor(TColor::GetColor("#8E0000"));
  e_dmesonraa->SetTextFont(42);
  e_dmesonraa->SetTextSize(legend_text_size);
  e_dmesonraa->SetFillStyle(1001);
  e_dmesonraa->SetLineColor(1);
  e_dmesonraa->SetLineStyle(1);
  e_dmesonraa->SetLineWidth(1);
  e_dmesonraa->SetMarkerStyle(kFullSquare);
  e_dmesonraa->SetMarkerSize(1);

  /* legend for hadron RAA */
  TLegendEntry *e_hadronraa=leg->AddEntry("hadronraa","Charged particles  (0-5%)  |#eta| < 1","lpf");
  e_hadronraa->SetFillColor(TColor::GetColor("#33ccff"));
  e_hadronraa->SetTextFont(42);
  e_hadronraa->SetTextSize(legend_text_size);
  e_hadronraa->SetFillStyle(1001);
  e_hadronraa->SetLineColor(1);
  e_hadronraa->SetLineStyle(1);
  e_hadronraa->SetLineWidth(1);
  e_hadronraa->SetMarkerStyle(kFullCircle);
  e_hadronraa->SetMarkerSize(1);
  
  /* legend for B meson RAA */
  TLegendEntry *e_bsraa=leg->AddEntry("bsraa","B_{s}^{0} R_{pA}","lpf");
  e_bsraa->SetFillColor(TColor::GetColor("#ff88ff"));
  e_bsraa->SetTextFont(42);
  e_bsraa->SetTextSize(legend_text_size);
  e_bsraa->SetFillStyle(1001);
  e_bsraa->SetLineColor(1);
  e_bsraa->SetLineStyle(1);
  e_bsraa->SetLineWidth(1);
  e_bsraa->SetMarkerStyle(kFullCircle);
  e_bsraa->SetMarkerSize(1);
  
  TLegendEntry *e_b0raa=leg->AddEntry("b0raa","B_{0} R_{pA}","lpf");
  e_b0raa->SetFillColor(TColor::GetColor("#ba8a98"));
  e_b0raa->SetTextFont(42);
  e_b0raa->SetTextSize(legend_text_size);
  e_b0raa->SetFillStyle(1001);
  e_b0raa->SetLineColor(1);
  e_b0raa->SetLineStyle(1);
  e_b0raa->SetLineWidth(1);
  e_b0raa->SetMarkerStyle(kFullCircle);
  e_b0raa->SetMarkerSize(1);
  
  TLegendEntry *e_bpraa=leg->AddEntry("bpraa","B_{+} R_{pA}","lpf");
  e_bpraa->SetFillColor(TColor::GetColor("#ffbf00"));
  e_bpraa->SetTextFont(42);
  e_bpraa->SetTextSize(legend_text_size);
  e_bpraa->SetFillStyle(1001);
  e_bpraa->SetLineColor(1);
  e_bpraa->SetLineStyle(1);
  e_bpraa->SetLineWidth(1);
  e_bpraa->SetMarkerStyle(kFullCircle);
  e_bpraa->SetMarkerSize(1);
  
  TLegendEntry *e_lumiuncert=leg->AddEntry("lumiuncert","pPb Luminosity Uncertainty","f");
  e_lumiuncert->SetFillColor(TColor::GetColor("#006600"));
  e_lumiuncert->SetFillStyle(1001);
  e_lumiuncert->SetTextSize(legend_text_size);
  e_lumiuncert->SetTextFont(42);
  e_lumiuncert->SetLineWidth(0);
  e_lumiuncert->SetMarkerStyle(kFullCircle);
  e_lumiuncert->SetMarkerSize(1);

  
  leg->Draw();

}
  
