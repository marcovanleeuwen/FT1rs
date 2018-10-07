TCanvas *c1 = 0;
TLegend *lg = 0;

void drawMany(HistoManager* hm, Int_t color=0, Int_t linewidth=0, Bool_t same=kFALSE, const char* cmt="")
{
  if (!c1) {
    c1 = new TCanvas("c1","c1");
    c1->Clear();
    c1->Divide(2,2);
    for (int i=1;i<=4;i++) {
      c1->cd(i);
      gPad->SetGridx();   gPad->SetGridy(); 
    }
    same = kFALSE;
    lg = new TLegend(0.2,0.2,0.5,0.5);
  }
  gStyle->SetOptStat(0);
  TString opt = same ? "l" : "al";

  c1->cd(1);
  hm->GetGraph(0)->Draw(opt.Data());
  gPad->SetLogx();
  if (color>0) hm->GetGraph(0)->SetLineColor(color);
  if (linewidth>0) hm->GetGraph(0)->SetLineWidth(linewidth);
  lg->AddEntry(hm->GetGraph(0),cmt,"lp");
  //
  c1->cd(2);
  hm->GetGraph(1)->Draw(opt.Data());
  hm->GetGraph(1)->SetMinimum(0.5);
  hm->GetGraph(1)->SetMaximum(3.);
  
  gPad->SetLogy();  gPad->SetLogx();
  if (color>0) hm->GetGraph(1)->SetLineColor(color);
  if (linewidth>0) hm->GetGraph(1)->SetLineWidth(linewidth);

  //
  c1->cd(3);
  hm->GetGraph(2)->Draw(opt.Data());
  gPad->SetLogy();  gPad->SetLogx();
  if (color>0) hm->GetGraph(2)->SetLineColor(color);
  if (linewidth>0) hm->GetGraph(2)->SetLineWidth(linewidth);

  //
  c1->cd(4);
  hm->GetGraph(3)->Draw(opt.Data());
  gPad->SetLogy();  gPad->SetLogx();
  if (color>0) hm->GetGraph(3)->SetLineColor(color);
  if (linewidth>0) hm->GetGraph(3)->SetLineWidth(linewidth);

  
}
