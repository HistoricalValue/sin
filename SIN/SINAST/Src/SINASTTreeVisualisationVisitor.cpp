#include "SINASTTreeVisualisationVisitor.h"

#include <stdio.h>
#include <iostream>

#include "Common.h"
#include "SINLogger.h"
#include "SINAssert.h"
#include "SINTreeNode.h"
#include "SINConstants.h"
#include "SINLoggerManager.h"

#define SIN_ASTTreeVisualisationVisitor_LoggerName "SIN::ParserAPI->Parser"
namespace SIN {

	ASTTreeVisualisationVisitor::ASTTreeVisualisationVisitor(OutputStream& _out):
	tabs(""), out(_out), logger_p(0x00)
	{
		Type<LoggerManager>::ref lm(*LoggerManager::SingletonGetInstance());
		lm.GetDefaultLoggerFactory()->DestroyLogger(lm.MakeStdoutLogger(SIN_ASTTreeVisualisationVisitor_LoggerName));
		logger_p = lm.GetLogger(SIN_ASTTreeVisualisationVisitor_LoggerName);
	}

	ASTTreeVisualisationVisitor::~ASTTreeVisualisationVisitor(void) {
	}

	void ASTTreeVisualisationVisitor::Visit(Type<ASTNode>::const_ref node) {
		out << tabs+node.Name();
	}

	//-----------------------------------------------------------------
	
	//void ASTTreeVisualisationVisitor::Visit (IdASTNode const & node) 
	//	{ Visit(dynamic_cast<ASTNode const &>(node)); }
	

	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (NumberASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }
	

	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (StringASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }
	

	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (NilASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (TrueASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (FalseASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (AddASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }
	

	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (SubASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (MulASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (DivASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (ModASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	////-----------------------------------------------------------------

	//void ASTTreeVisualisationVisitor::Visit (IncrASTNode const & node)
	//	{ Visit(dynamic_cast<ASTNode const &>(node)); }


	////-----------------------------------------------------------------

	//void ASTTreeVisualisationVisitor::Visit (DecrASTNode const & node)
	//	{ Visit(dynamic_cast<ASTNode const &>(node)); }
	

	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (LtASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (GtASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (LeASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (GeASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (EqASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (NeASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (OrASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	//void ASTTreeVisualisationVisitor::Visit (NotASTNode const & node)
	//	{ Visit(dynamic_cast<ASTNode const &>(node)); }


	//-----------------------------------------------------------------

	void ASTTreeVisualisationVisitor::Visit (AndASTNode const & node)
		{ Visit(dynamic_cast<ASTNode const &>(node)); }


	////-----------------------------------------------------------------

	//void ASTTreeVisualisationVisitor::Visit (ForASTNode const & node)
	//	{ Visit(dynamic_cast<ASTNode const &>(node)); }


	////-----------------------------------------------------------------

	//void ASTTreeVisualisationVisitor::Visit (WhileASTNode const & node)
	//	{ Visit(dynamic_cast<ASTNode const &>(node)); }


	////-----------------------------------------------------------------

	//void ASTTreeVisualisationVisitor::Visit (IfASTNode const & node)
	//	{ Visit(dynamic_cast<ASTNode const &>(node)); }


	////-----------------------------------------------------------------

	//void ASTTreeVisualisationVisitor::Visit (IfElseASTNode const & node)
	//	{ Visit(dynamic_cast<ASTNode const &>(node)); }


	void ASTTreeVisualisationVisitor::AddTab(void) 
		{ tabs += "\t"; }
	
	void ASTTreeVisualisationVisitor::RemoveTab(void) {
		if (tabs != "") 
			tabs.Erase(tabs.Length()-1, 1);
	}


} // namespace SIN
