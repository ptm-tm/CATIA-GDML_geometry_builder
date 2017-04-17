void Import_GDML(TString filename)
{
	// Check that the input file is the GDML file
	if (!filename.EndsWith(".gdml")) {
		cerr << "Please specify a GDML file as input!" << endl;
		return;
	}

	// Create geometry manager
	TGeoManager* geom = new TGeoManager("geom", "geom");

	// Import the input GDML file
	geom->Import(filename);
}
