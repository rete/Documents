{
	TCanvas *pCanvas = new TCanvas("canvas", "energy calibration");
	pCanvas->SetRightMargin(0.05);
	pCanvas->SetTopMargin(0.05);
	pCanvas->cd();

	TF1 *pAlphaFunc = new TF1("alpha", "0.0385315 + x*4.22584e-05 + x*x*-7.54657e-09", 0, 1400);
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


	TF1 *pBetaFunc = new TF1("beta", "0.0784297 + x*-5.69439e-05 + x*x*-4.95924e-08", 0, 1400);
	pBetaFunc->SetLineColor(kBlue);
	pBetaFunc->SetLineWidth(2);
	pBetaFunc->Draw("same");

	TF1 *pGammaFunc = new TF1("gamma", "0.127212 + x*4.56414e-05 + x*x*1.41142e-08", 0, 1400);
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
