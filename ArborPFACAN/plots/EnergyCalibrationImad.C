{
	TCanvas *pCanvas = new TCanvas("canvas", "energy calibration");
	pCanvas->SetRightMargin(0.05);
	pCanvas->SetTopMargin(0.05);
	pCanvas->cd();

// double bestX1 = 0.039081; 
// double bestY1 = 0.077336;
// double bestZ1 = 0.119574;
// double bestX2 = 3.23877e-05;
// double bestY2 = 7.71267e-06;
// double bestZ2 = 2.40615e-05;
// double bestX3 = -2.04628e-08; 
// double bestY3 = -3.49567e-09;
// double bestZ3 = 2.80403e-08;

	TF1 *pAlphaFunc = new TF1("alpha", "0.039081 + x*3.23877e-05 + x*x*-2.04628e-08", 0, 1400);
	pAlphaFunc->SetLineColor(kGreen);
	pAlphaFunc->SetLineWidth(2);
	pAlphaFunc->Draw();
	pAlphaFunc->GetYaxis()->SetRangeUser(-0.2, 0.5);
	pAlphaFunc->GetXaxis()->SetRangeUser(0, 1400);
	pAlphaFunc->GetYaxis()->SetLabelSize(0.04);
	pAlphaFunc->GetXaxis()->SetLabelSize(0.04);
	pAlphaFunc->GetYaxis()->SetTitleSize(0.04);
	pAlphaFunc->GetXaxis()->SetTitleSize(0.04);
	pAlphaFunc->GetYaxis()->SetTitle("Calibration coefficients");
	pAlphaFunc->GetXaxis()->SetTitle("N_{hit}");
	pAlphaFunc->SetTitle("");
	pCanvas->Update();


	TF1 *pBetaFunc = new TF1("beta", "0.077336 + x*7.71267e-06 + x*x*-3.49567e-09", 0, 1400);
	pBetaFunc->SetLineColor(kBlue);
	pBetaFunc->SetLineWidth(2);
	pBetaFunc->Draw("same");

	TF1 *pGammaFunc = new TF1("gamma", "0.119574 + x*2.40615e-05 + x*x*2.80403e-08", 0, 1400);
	pGammaFunc->SetLineColor(kRed);
	pGammaFunc->SetLineWidth(2);
	pGammaFunc->Draw("same");

	TLegend *pLegend = new TLegend(0.7, 0.7, 0.85, 0.85);
	pLegend->SetLineColor(0);
	pLegend->SetFillColor(0);
	pLegend->AddEntry(pAlphaFunc, "#alpha (N_{hit})", "l");
	pLegend->AddEntry(pBetaFunc, "#beta (N_{hit})", "l");
	pLegend->AddEntry(pGammaFunc, "#gamma (N_{hit})", "l");
	pLegend->Draw();

	TPaveText *pText = new TPaveText(0.60, 0.81, 0.93, 0.86, "tbNDC");
	pText->SetLineColor(0);
	pText->SetFillColor(0);
	pText->SetBorderSize(0);
	pText->AddText("CALICE Preliminary");
	pText->SetTextColor(kGray+2);
	pText->Draw();

}
