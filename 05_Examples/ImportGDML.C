void ImportGDML(TString filename)
{
	TGeoManager* geom = new TGeoManager("geom", "geom");
	geom->Import(filename);
	TBrowser* bro = new TBrowser("bro");
}