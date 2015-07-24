#include "csvExport.h"


csvExport::csvExport(doubleVector *tb, doubleVector *R, uint p, doubleVector *X, uint n){
/// inicializo los streams para poder imprimir después más fácil	

	QDateTime current = QDateTime::currentDateTime();
	
	QString fileName = "Simulacion-"+current.toString("yyyy-MM-dd HH:mm:ss")+".csv";
	
	
	File.setFileName(fileName);
	File.open( QIODevice::ReadWrite | QIODevice::Truncate  );
	
	stream.setDevice( (QIODevice*)  &File );
	stream.setCodec("UTF-8");
	
	//~ 
	//~ QString header = "########################################################\n";
	//~ 
	//~ header+= "\n Simulación "+ current.toString("yyyy-MM-dd HH:mm:ss")+"\n\n";
	//~ 
	//~ header+= " Tiempo de muestreo: \n\tTs = " + QString::number(Ts,'f', 6)+"\n\n";
	//~ 
	//~ Mat *mats[7]= {control->getMat(mat::A),
				  //~ control->getMat(mat::B),
				  //~ control->getMat(mat::C),
				  //~ control->getMat(mat::D),
				  //~ control->getMat(mat::Phi),
				  //~ control->getMat(mat::Psi),K};
	//~ QString nombre[7]={"A","B","C","D","Phi","Psi","K"};
	//~ 
	//~ for (int i = 0; i < 7; i++) {
		//~ if (mats[i]!= 0){
			//~ header += " Matriz "+nombre[i]+":\n";
			//~ 
			//~ QString matStr= QString::fromStdString( mat2str(*mats[i]));
			//~ 
			//~ matStr.replace("\n","\n\t");
			//~ 
			//~ header += "\t"+matStr+"\n\n";
		//~ }
	//~ }
	//~ header+= "########################################################";
	//~ 
	//~ header.replace("\n","\n#");
	//~ stream << header;
	//~ 
	//~ 
	//~ 
	
	
	stream << "n,tiempo,";
	for (uint i = 0; i < p; i++)	
		stream << QString("r%1,").arg(i);
	
	for (uint i = 0; i < n; i++)	
		stream << QString("x%1,").arg(i);
	
	stream << "\n";

	for (uint i = 0; i < tb->size() ; i++) {
		stream << i << ",";
		stream << tb->at(i) << ",";
		
		for (uint j = 0; j < p ; j++)
			stream << R[j].at(i) << ",";
			
		for (uint j = 0; j < n; j++){
			stream << X[j].at(i);
			if ( j < n-1 )
				stream << ",";
		 }
		 
		 stream << "\n";
		
	}

}
