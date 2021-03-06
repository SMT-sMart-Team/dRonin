/**
 ******************************************************************************
 * @file       tempcompcurve.h
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2013
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup ConfigPlugin Config Plugin
 * @{
 * @brief Display the results of temperature compensation
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 */

#ifndef TEMPCOMPCURVE_H
#define TEMPCOMPCURVE_H

#include <QWidget>

#include "qwt/src/qwt.h"
#include "qwt/src/qwt_plot.h"
#include "qwt/src/qwt_plot_curve.h"
#include "qwt/src/qwt_scale_draw.h"
#include "qwt/src/qwt_scale_widget.h"
#include "qwt/src/qwt_plot_grid.h"

class TempCompCurve : public QwtPlot
{
    Q_OBJECT
public:
    explicit TempCompCurve(QWidget *parent = nullptr);

    //! Show calibration data for one of the channels
    void plotData(QList<double> temp, QList<double> gyro, QList<double> coefficients);
signals:

public slots:

private:
    void clearCurves();

    QVector<QPointF> points;
    QVector<QPointF> fit;
    QwtPlotCurve *dataCurve;
    QwtPlotCurve *fitCurve;
};

#endif // TEMPCOMPCURVE_H
